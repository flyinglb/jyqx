// Room: /d/suzhou/leitai.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��̨ǰ�㳡");
	set("long", @LONG
������������̨ǰ���һ�����͹㳡���������������̨
�ϱ��䣬��������ɽ�˺��������Ҳ���������֣���ô������
����̨���Ա��԰ɡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"hutong1",
	]));
	setup();
	replace_program(ROOM);
}

