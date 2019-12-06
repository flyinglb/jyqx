// room: laozhai.c
// Jay 4/8/96
#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string arg);

void create()
{
    set("short", "������լ");
    set("long", @LONG
�����Ǹ����ھ�����ͷ�������ڸ����ľɾӡ����ڵļҾߺ������˵�
���ڵ��ϡ������һ�ǽ���һ��֩���������ﵽ���ǳ�������Ȼ���Ѿ���
��û����ס�ˡ�����ľ�ͷ��һ����(men)�����ѱ�̮����ש�ߵ�ס�ˡ�
LONG );

    set("exits", ([
        "south" : __DIR__"xijie",
    ]));

    set("item_desc", ([
        "men" : "�������ѱ���ס�޷�ͨ�У����������(break)����\n",
    ]) );
    set("no_clean_up", 0);
    setup();
}

void init()
{
    object book, me;
    me = this_player();
    add_action("do_break", "break");
    if ((objectp(book=present("kuihua baodian",me)))) {
	remove_call_out("buqun_rob");
	call_out("buqun_rob", 1, me, book);
    }
}

int do_break(string arg)
{
    int n;
    n = this_player()->query("neili");
    if( !arg || arg!="men" ) {
        write("��Ҫ��������˵Ķ�����\n");
        return 1;
    }
    message_vision(
"$N�ߵ�����ǰ���ݳ��������ʽ������һ������˫��ͬʱ�ĳ���\n", this_player());
    if (n>=200) {
        message_vision(
        "$Nֻ��һ�����죬$N�������ˣ�\n", this_player());
        set("exits/north", __DIR__"houyuan");
        this_player()->set("neili",n-200);
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else {
        message_vision(
"$N���һ���������������ʲôҲû����������$N����������ǿ��\n", this_player());
        this_player()->set("neili",0);
    }
    return 1;
}

void close(object room)
{
    message("vision","���ϵ�שͷ�߿�ϡ�ﻩ��̮���������ֵ�ס�˺��š�\n", room);
    room->delete("exits/north");
}

void buqun_rob(object me, object book)
{
    message_vision(HIY "��Ȼ��һ�������˴Ӻ�Ӱ�����˳�����һ�С��з����ǡ���"
        "���г�����˸\n����������$N���ʺ�\n" NOR,  me);

    if( !me->query_skill("pixie-jian", 1) ) {
        message_vision("$Nһ�֮�䣬�ѱ������˴��У�\n", me);
        book->move(environment(me));
        destruct(book);
        me->unconcious();
    }
    else {
        message_vision(
        "$N����Ʈ����������ȣ�ת�˼�ת���Ʋ��������˵���󣬶����"
        "��������һ�С�\n", me);
    }
    write("������˫���أ�Խǽ���ߡ�\n��о������˵��������ǻ�ɽ�ɵġ�\n");
}
