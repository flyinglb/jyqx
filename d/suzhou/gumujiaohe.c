// Room: /d/suzhou/gumujiaohe.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ľ��ڭ");
	set("long", @LONG
��ľ��ڭ�ںɻ��������棬һ�Ų�ͬͼ����©����ʹ��͸
��©�����������в���ˮ��ɽɫ�͸ߵʹ����¥�󣬴˴��;���
�С��Ʋ���Ӱ��֮��������׿���ң������������ɪ¥����
��һ�֡�ͥԺ��������Ϳռ䲻��֮�С�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"hehuating",
		"southwest" : __DIR__"chitang",
	]));
	setup();
	replace_program(ROOM);
}

