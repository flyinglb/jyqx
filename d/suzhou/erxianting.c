// Room: /d/suzhou/erxianting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤ��ǧ��ʯ���࣬���ڱ��Ρ�ͤ��Ƕ����ʯ�����ֱ�
��������γ��������ƴ�������������ͤ����������ʯ���
����������˵��ԭ���Σ�Ԫ����Ԫ����Ԫ������������������
�����񳯻��������١���
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"qianrenshi",
		"north" : __DIR__"bailianchi",
	]));
	setup();
	replace_program(ROOM);
}

