// Room: /d/hengshan/huixiantai.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���Է�㳡");
        set("long", @LONG
�����Ǻ�ɽ������Է�嶥�Ĺ㳡�������︩�Ⱥɽ�������
�ú��Ժ�ɽ�ǻ��ı�����ɽ֮�ڣ�����Ҳ�����𽭺��ĺ�ɽ�ɵĸ�
���صء�
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"  : __DIR__"shandao2",
           "north"     : __DIR__"baiyunan",
        ]));
	set("objects", ([
		__DIR__"npc/yi" : 1,
		__DIR__"npc/qing" : 1,
	]));
        set("outdoors", "hengshan");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

