//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��·");
	set("long", @LONG
����·������ɽ��ɽ֮�����ߴ������ͨ��������������Ʈ�Ŵ��̵Ĵ�
ׯ����ֱ��ֱ�µ�ɽ�ھ�����Ľ��£�����Ʈ�������������������ֱ���ɼ
�������㲻�Ҷ����¿����ƺ��࿴һ�۶�������ͷ�ζ�ʧ����������������ͷ
�������¡�
LONG );
	set("exits", ([
		"west"  : __DIR__"jilu2",
		"east"  : __DIR__"pingchuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

