// Room: /d/fuzhou/wuyishan2.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����Ϫ");
	set("long", @LONG
����Ϫ��ɽ�������������ۣ�������֮�У�ˮɫ��͸����
�ֿ�����������ɽ��ת�����ˮ��������ɽ��ˮɫ����Ϊһ�塣
�ذ�������Ρ�룬��Ů���������������¡�
LONG );
	set("exits", ([
		"east"      : __DIR__"wuyishan1",
		"west"      : __DIR__"wuyishan5",
		"northup"   : __DIR__"wuyishan6",
		"south"     : __DIR__"wuyishan7",
	]));
	set("resource/water", 1);
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

