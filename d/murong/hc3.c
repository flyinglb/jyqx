// /u/beyond/mr/hc3.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",MAG"������"NOR);
         set("long",@long
���Ų�����, ֻ�������г�ɽ�軨����ޱ�������, �������ǣţ��,
���º�, Ǿޱ֮��Ҳ��һ�䶼�ޡ��߳���ʮ�ɺ�, ֻ��ɽ��Ʒ�ֽ���, ż��
Ҳ��һ�������㲻��, ȴҲ���ֲ����䷨��
long);
         set("outdoors","mr");
         set("exits",([
             "north" : __DIR__"hc2",
             "east" : __DIR__"hc",
]));
set("objects",([
__DIR__"obj/chahua" : 1,
__DIR__"obj/chahua1" : 1,
]));
         setup();
         replace_program(ROOM);
}

