// Room: /d/shaolin/hsyuan1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����Ժһ��");
	set("long", @LONG
�����Ǻ���Ժ���͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�
ǽ��һ�������ż���������и�������������ˡ����ݴ�����
��׭�֣������������ڣ��ƺ��Ǹ�����²衣һλСɳ����һ
�ߴ���վ����
LONG );
	set("exits", ([
		"west" : __DIR__"wuchang3",
		"east" : __DIR__"zhulin1",
		"south" : __DIR__"zoulang7",
		"north" : __DIR__"hsyuan2",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-he" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

