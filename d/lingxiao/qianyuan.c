// Room: qianyuan.c

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
        set("short","ǰԺ");
        set("long",@LONG 
�����������ǵ�ǰԺ���������Ӵ󶼾�ס�ڴ˺���������
һ�����˺�Χ�ֵ�ī÷��������ڣ���ζ�ҷ�������Ĵ�Ժ�
��ɽ����͸��ī÷�Ļ������£���ѩ����ӳ��һ������ߡ�һֻ
ѩ���������������裬�ڰ���ӳ��������Ȥ�� 
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"dadian",
            "west"  : __DIR__"huajing", 
            "north"  : __DIR__"zhongting",
        ]));
        set("objects", ([
                __DIR__"npc/xuehe" : 1,
                __DIR__"obj/ban" : 1,
        ]));
        set("no_clean_up", 0);
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

