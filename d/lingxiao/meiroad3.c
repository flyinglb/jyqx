//LUCAS 2000-6-18
// Room: meiroad3.c

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
        set("short","÷��");
        set("long",@LONG
������������÷��վ������ƺ�����������������Զ����
�ܿ����Ĵ���һ����һ��΢�紵��������÷�ĺ����е���һ����
����ͬʱ���ǹɽ�����Ƣ�����㣬�͵�ÿ���˵����С����߾���
�����ǵĹ۾�ʤ��Ϸ÷ͤ�ˡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "west"  : __DIR__"meiroad1",
            "east"  : __DIR__"ting",
        ]));
        set("objects", ([ 
                __DIR__"obj/ban" : 1,
    ])); 
        setup();
}

void init()
{
 add_action("do_pick","pick");
}

int do_pick(string arg)
{
 object me=this_player();
 object ob;
 if (!arg||arg!="hua")
  return notify_fail("��Ҫժʲô��\n");
 ob=new(__DIR__"obj/mei");
 ob->move(me);
 message_vision("$N��·�Ե�����ժ��һ��÷����\n" , me);
 return 1;
}

