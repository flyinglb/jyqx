// Room: /d/fuzhou/fzroad2.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
������խխ������ɽС���ϣ�ɽ·��᫣�����ɭɭ�����г�
��Ұ�޳�û����ν��������������ѡ����ϲ����ۡ�������ų�
��Ϫ������������ڶ��ϵ�����ɽ�ˡ�
LONG );
	set("exits", ([
		"northup" : __DIR__"erbapu",
		"southup" : __DIR__"fzroad3",
		"west"    : __DIR__"wuyishan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

