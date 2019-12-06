#include <ansi.h>

inherit ROOM;
string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
	__DIR__"npc/girl",
});

void create()
{
    set("short", "����");
    set("long", @LONG
���Ǽ�ܴ�����ݡ�����վ�ż����������.��ס������������
����,������Զ,ȴҲ�������õ�����������������֮��.
LONG
    );

    set("exits", ([
		"south" : __DIR__"road2",
		"north" : __DIR__"dating",
    ]));
    set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
    replace_program(ROOM); 
}

