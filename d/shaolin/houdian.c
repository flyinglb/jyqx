// Room: /d/shaolin/houdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����ģ�������߶���ˮĥʯ�ڣ��ο���ʮ���޺���Ф��
�����ˣ�������һ��ˮ����ˮ�澻���������������ᣬ��Ի����
��������������ˮ������������и��Ŷ���ͨ�����೤�������ȡ�
LONG );
	set("exits", ([
		"west" : __DIR__"zoulang2",
		"east" : __DIR__"zoulang3",
		"southdown" : __DIR__"guangchang4",
		"north" : __DIR__"wuchang",
	]));
	set("valid_startroom",1);
	set("resource/water",1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-ru" : 1,
		__DIR__"npc/seng-bing3" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

