// Room: /d/xiangyang/northroad2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
	set("long", @LONG
����һ������ʯ�̾͵Ĵ����ֻ�����治ʱ�������ɱ�
�������ޣ������ǳ��С��������Ƕ��ֽֿڣ�����Ҳ��һ����
�ֿڣ�����󿴵�һ�����ͨ�����档������һ���ϸǺ�ɫ��
���ߵĸ�ǽ�������������سǴ�����ĸ�ۡ��
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"jiekou2",
		"west"  : __DIR__"dingzi",
		"north" : __DIR__"majiu",
	]));
	setup();
	replace_program(ROOM);
}

