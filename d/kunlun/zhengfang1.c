//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�ƺ��������д�լԺ������������������ģ�һ�ž޴�İ����������Ÿ�
���Ρ��ڷ��������ǽ����������һ����ɽ��ˮͼ���������Ϸ����ķ��ı���
����һֻ˶��ıʡ����䱱������ͨ���լ�����滹��һ��С�ţ�ƽʱ���ǹ�
�ŵġ�
LONG );
	set("exits", ([
		"west"  : __DIR__"huilang",
		"north" : __DIR__"neiyuan1",
		"south" : __DIR__"beiyuan",
	]));
	set("objects", ([
		__DIR__"npc/zhuchangling" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

