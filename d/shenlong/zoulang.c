#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
����һ������,���߶���ʯͷ����, �����Ǵ���,�����ǳ�
��,���������䳡,��������Ϣ��.
LONG );

    set("exits", ([
	"east" : __DIR__"chufang",
	"west" : __DIR__"dating",
	"south" : __DIR__"wuchang",
	"north" : __DIR__"xiuxishi",
    ]));
    set("objects", ([
	CLASS_D("shenlong")+"/zhang" : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
    replace_program(ROOM); 
}

