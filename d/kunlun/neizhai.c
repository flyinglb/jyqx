//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��լ");
	set("long", @LONG
����һ�侫�ű��µķ��䣬���ڼҾ߰��貢���ݻ�����ȴ��ʾ�����˸߹�
�������������һ���ɫ�����ͭ�����ӳ��г�����ֻ�г���߹���˲���ӵ
�������Ļ�����
LONG );
	set("exits", ([
		"south" : __DIR__"neiyuan1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

