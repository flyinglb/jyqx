// /u/beyond/mr/anbian2.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"����"NOR);
         set("long",
"ԶԶ��ȥ��ֻ��һ��С���ϰ˾ż䷿�䣬����������¥������������Լ¶\n"
"��һ���Ʒ���"HIY"����ˮ�"NOR"����\n"
);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"shuixie",
]));
         setup();
         replace_program(ROOM);
}

