// /u/beyond/mr/houyuan1.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"��Ժ"NOR);
         set ("long",@long
����ˮ鿵ĺ�Ժ��Ժ�м�ɽˮʯ����һ��͸�����ϱ��һ��ķ��ֻ
����������һ�������͵�С�š����߾��Ǿ����������������ˡ�������һ��
ͨ�����С����ľ�ţ������ǰ��ߣ�����������̫����
long);
         set("outdoors","mr");
         set("valid_startroom", 1);
         set("exits",([
             "north" : __DIR__"shuixie",
             "west" : __DIR__"muqiao",
             "east" : __DIR__"yanziwu",
             "south" : __DIR__"anbian3",
]));
         setup();
         replace_program(ROOM);
}

