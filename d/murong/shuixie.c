// /u/beyond/mr/shuxie.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"����ˮ�"NOR);
         set("long",@long
��䷿��С������, ��Ϊ���š�С���Ҷ���д��"����ˮ�"�ĸ�����, 
������Ϊ������������һ��С·����֪��ͨ������ġ�����ǰ�ߣ��͵���
"������"���ϱ���ˮ鿵ĺ�Ժ��
long);
         set("exits",([
             "north" : __DIR__"anbian2",
      "west" : __DIR__"anbian4",
             "south" : __DIR__"houyuan1",
]));
set("objects",([
__DIR__"npc/azhu" : 1,
]));
setup();
             replace_program(ROOM);
}

