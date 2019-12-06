//LUCAS 2000-6-18
// Room: meiroad2.c

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
        set("short","÷��");
        set("long",@LONG 
��Ҳ��һ������÷�������С��������ⲻͬ���ǣ������
����÷��������ȫ������Ѫ����õĺ�÷������ƬƬƮ�䣬�䵽
��׵�ѩ���ϣ�����һ�������˳�����ˣ��ڸ��Լ��������˴�
��ʱ����С�Ĵ�������ָ��������һ��Ѫ�������˰׾���һ����
һֻͨ��ѩ�׵�ѩ���ڵ�����Ȼ���裬��ң�Եá�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "west"  : __DIR__"stone",
            "east"  : __DIR__"meiroad1",
        ]));
        set("objects", ([
                __DIR__"npc/xuehe" : 1,
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

