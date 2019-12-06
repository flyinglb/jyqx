// jianzuo.c
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
        set("objects", ([
//                CLASS_D("btshan") + "/ouyangke" : 1,
//                 __DIR__"obj/jiao" : 1,
        ]));
        set("exits", ([
                  "north" : __DIR__"yongdao1",
        ]));
        set("item_desc", ([
                "��ڣ" : "��ħ������ܼ��޵������£�������˹��\n",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_push", ({"push","break"}) );
}
int do_push(string arg)
{
        int n;
        object ob, me = this_player();

        n = this_player()->query("neili");
        if( !arg || arg != "��ڣ")
        {
                write("��Ҫ��ʲô? \n");
                return 1;
        }
        if (me->query_temp("marks/jinshe") == "1")
        {
                if (n > 200 && query("tiesword_count") == 1)
                {
                        message_vision(
"$N���þ�ȫ���ٴ��ƶ���ڣ�µ���ʯ�������ֽ�������
�ߣ���Ȼ����һ������ͷ������һ�������������Ȼ��
�Ѻ�����Ľ���\n", me);
                        ob = new(__DIR__"tiesword");
                        ob->move(environment(me));
                        me->set_temp("marks/jinshe", "2");
                        add("tiesword_count", -1);
                }
                else
                {
                        message_vision("$N�ڲ���ʲô�����˼��¾Ͳ�����ˡ�\n", me);
                        me->set("neili",0);
                }
        }
        else
        {
                if (n > 100 && query("ziwei_count") == 1)
                {
                        message_vision(
"$N�����ƶ���ڣ�µ���ʯ ����һ�ᣬ��Ȼ����һ��������һ��������
�ƽ����һ�����������п���ʯ���������˼��£������Ա���ʯ��ԭ
������һֻ�������Ľ���\n", me);
                        ob = new(__DIR__"ziwei");
                        ob->move(environment(me));
                        me->set_temp("marks/jinshe", "1");
                        add("ziwei_count", -1);
                }
                else
                {
                        message_vision("$N�ڲ���ʲô�����˼��¾Ͳ�����ˡ�\n", me);
                        me->set("neili",0);
                }
        }
        return 1;
}
