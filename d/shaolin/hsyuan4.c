// Room: /d/shaolin/hsyuan4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����Ժ�Ĳ�");
	set("long", @LONG
�����Ǻ���Ժ���͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�
ǽ��һ�������ż���������и�������������ˡ����ݴ�����
��׭�֣������������ڣ��ƺ��Ǹ�����²衣һλСɳ����һ
�ߴ���վ����
LONG );
	set("exits", ([
		"east" : __DIR__"wuchang3",
		"west" : __DIR__"zhulin4",
		"south" : __DIR__"zoulang6",
		"north" : __DIR__"hsyuan5",
	]));
	set("resource/water",1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-xu" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

