// Room: /d/suzhou/yunhematou.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�˺���ͷ");
	set("long", @LONG
�������˺���ͷ�����ǳ�͢����Ҫ����ˮ½�ؾ�֮������
����������ֻ���ش��󣬼��䷱æ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"xidajie1",
	]));
	setup();
	replace_program(ROOM);
}

