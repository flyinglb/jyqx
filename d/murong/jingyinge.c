// /u/beyond/mr/jingyinge.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",RED"������"NOR);
         set("long",@long
�������������Եĺó��������ﾲ���ĵģ�û�����˵ķԸ���˭Ҳ
���ܹ������������ǽ�Ϲ���һ��ͼ��
long);
       
         set("exits",([
             "east" : __DIR__"neitang",
             "west" : __DIR__"cl6-2",
             "south" : __DIR__"cl6-5",
]));
         setup();
}


