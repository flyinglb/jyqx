#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "��Ժ");
    set("long", @LONG
����һ���ƾɵĴ�Ժ��Ժ��ʮ�ֿ��������ݰ��ˡ�����
һ���쾮,��������������.
LONG );
    set("exits", ([
	"north" : "/d/city2/zhuang5",
	"south" : "/d/city2/zhuang3",
    ]));
    set("objects", ([
		"/d/shenlong/npc/zhang3": 1,
    ]));
    set("outdoors", "city2");
//    set("no_clean_up", 0);
    setup();
    replace_program(ROOM); 
}


