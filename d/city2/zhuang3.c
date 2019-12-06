#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_break(string arg);
int do_climb(string arg);

void create()
{
    set("short", "ׯ������");
    set("long", @LONG
���������ʿׯ�ʳǵľɾӡ��Դ�������͢ץ�ߺ�,��������
û����ס�ˡ�һ�ȴ���(men)������,��Χ�Ǹ߸ߵ�Χǽ(wall).
һ�ж��ܸɾ�,��û�л����ٻҳ���
LONG );
    set("exits", ([
        "south" : __DIR__"zhuang2",
    ]));
    set("item_desc", ([
        "men" : "�����������ŵģ����������(break)����\n",
        "wall" : "ǽ�ܸߣ����ܷ�����ȥ(climb)��\n",
    ]) );
    set("no_clean_up", 0);
    setup();
}

void init()
{
    object me;
    me = this_player();
    add_action("do_break", "break");
    add_action("do_climb", "climb");
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
    "$N�ߵ���ǰ������һ������˫��ͬʱ�ĳ���\n", this_player());
        
    if (n>=200) {
        message_vision(
        "$Nֻ��һ�����죬$N�������ˣ�\n", this_player());
        set("exits/north", __DIR__"zhuang4");
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

int do_climb(string arg)
{
    int n;
    n = this_player()->query_skill("dodge");
    if( !arg || arg!="wall" ) {
        write("��Ҫ����������\n");
        return 1;
    }


    message_vision(
    "$N��ǽǰվ��,����һ��������ȻԾ��.\n", this_player());
        
    if (n>=80) {
        message_vision(
        "ֻ��$N�����ǽ��һ��,����ȻƮ��Ժ��.\n", this_player());
        this_player()->move("/d/city2/zhuang4");
    }
    else if (n>=50) {
        message_vision(
        "ֻ��$N˫����ǽ��һ��,��ǿ����Χǽ,����Ժ��.\n", this_player());
        this_player()->move("/d/city2/zhuang4");
    }
    else {
        message_vision(
        "$N�߸�Ծ��,�ɻ���һ�����,�������Ṧ�����á�\n", this_player());
     }
    return 1;
}

void close(object room)
{
    message("vision","��֨ѽһ���ֺ�����,�����й�\n", room);
    room->delete("exits/north");
}

