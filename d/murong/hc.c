// /u/beyond/mr/hc.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"������"NOR);
         set("long",@long
���Ų�����, ֻ�������г�ɽ�軨����ޱ�������, �������ǣţ��,
���º�, Ǿޱ֮��Ҳ��һ�䶼�ޡ��߳���ʮ�ɺ�, ֻ��ɽ��Ʒ�ֽ���, ż��
Ҳ��һ�������㲻��, ȴҲ���ֲ����䷨���������ׯ���ˡ�
long);
         set("outdoors","mr");
         set("exits",([
             "north" : __DIR__"anbian",
             "east" : __DIR__"zhuangmen",
             "west" : __DIR__"hc3",
]));
         setup();
         replace_program(ROOM);
}

