//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ּ�С��");
	set("long", @LONG
����һ��ׯ�Ӻ��������е�һ��С·��С·��᫲�ƽ�������Ǻܶ಻����
���������һЩ�Ѿ���������ֻʣ����׮�ˡ�
LONG );
	set("exits", ([
		"east" : __DIR__"lin3",
		"north" : __DIR__"mudi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

