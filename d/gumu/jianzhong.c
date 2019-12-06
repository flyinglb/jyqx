// jianzhong.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ڣ");
        set("long", @LONG   
������ľ�Դ䣬ɽ����ѣ����Ų���ȥ���ͷ羰������
������һ���ͱ�֮ǰ�����ͱڱ���һ����������磬����
�����ͱ��в����Լ��ʮ���ɴ�������һ�������ɼ�����
��ʯ������һ��ƽ̨��ʯ�������̵����֡���Ŀ����������
���ǡ���ڣ����������
LONG
        );
        set("outdoors", "city");
        set("exits", ([
                  "north" : __DIR__"yongdao1",
                  "west" : __DIR__"xibian",
        ]));
        set("item_desc", ([
                "��ڣ" : "��ħ������ܼ��޵������£�������˹��\n",
        ]));

        set("tiesword_count",random(10)-7);
        set("ziwei_count",random(10)-6);
        setup();
}

void init()
{
        add_action("do_push", ({"push","break"}) );
}

int do_push(string arg)
{
        object ob, me = this_player();
        int n = me->query("neili");
        
        if( !arg || arg!="��ڣ" ) {
                write("��Ҫ��ʲô? \n");
                return 1;
        }
        if( n<200 ) {
                write("���Ѿ�û�����������ˡ�\n");
                return 1;
        }
        
        if (me->query_temp("tmark/��") == 1) {
                if (n > 200 && query("tiesword_count") > 0)
                {
                        message_vision(
"$N���þ�ȫ���ٴ��ƶ���ڣ�µ���ʯ�������ֽ�������
�ߣ���Ȼ����һ������ͷ������һ�������������Ȼ��
�Ѻ�����Ľ���\n", me);
                        ob = new(__DIR__"/obj/tiesword");
                        if(!ob->move(me)) ob->move(environment(me));
CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"�õ��˹�Ĺ�ر�--��������\n");
                        set("tiesword_count", 0);
                } else {
                        message_vision("$N���˼��£�ʲôҲû���ڵ���\n", me);
                }
        } else {
                if (n > 200 && query("ziwei_count") > 0) {
                        message_vision(
"$N�����ƶ���ڣ�µ���ʯ ����һ�ᣬ��Ȼ����һ��������һ��������
�ƽ����һ�����������п���ʯ���������˼��£������Ա���ʯ��ԭ
������һֻ�������Ľ���\n", me);
                        ob = new(__DIR__"/obj/ziwei");
                        if(!ob->move(me)) ob->move(environment(me));
CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"�õ��˹�Ĺ�ر�--��ޱ����\n");
                        me->set_temp("tmark/��", 1);
                        set("ziwei_count", 0);
                } else {
                        message_vision("$N���˼��£�ʲôҲû���ڵ���\n", me);
                }
        }
        me->add("neili",-50);
        return 1;
}

int valid_leave(object me, string dir)
{
    mapping myfam;
    me = this_player();
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "��Ĺ��")) && (dir == "west"))
      return notify_fail("�ǹ�Ĺ�ɵ��ӣ�����ֹ���ɡ�\n");
    else  return 1;
}
