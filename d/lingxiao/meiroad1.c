//LUCAS 2000-6-18
// Room: meiroad1.c

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
        set("short","÷��");
        set("long",@LONG
����һ��������÷������Ĵ�����������������ǵĴ����
�����ˡ����������÷�㣬����Ϊ����������÷�����߽�ȴ�ŷ�
�֣�����ֻ�����ú�Χ�ֵİ�÷����������ı��衣��ʵ����÷
����ѩ���ѷֲ����ˡ����������������÷��ѷѩ���ְף�ѩȴ
��÷һ���㡱�Ļ�����˭Ҳ�������ˡ���÷����ѩ��˭�ף�˭�㣬
�ֵó�����
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"iceroad3",
            "enter"  : __DIR__"dadian",
            "west"  : __DIR__"meiroad2",
            "east"  : __DIR__"meiroad3",
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 2,
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
 message_vision("$N��·�Ե�����ժ��һ��"+ob->query("name")+"��\n"NOR, me);
 return 1;
}

