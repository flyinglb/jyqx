// Room: /d/xiangyang/westroad1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
	set("long", @LONG
����һ����ʯ�̾͵Ĵ�֡�������������������һ���ܸ�
�Ĳ�¥��������һ�¸��ź�ɫ�����ߵĸ�ǽ�������ǹ�����Ժ��
���������������ֺŵĿ͵꣬��������ʯ�̵Ĵ�֡�
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"kedian",
		"south" : __DIR__"westjie2",
		"north" : __DIR__"westroad2",
	]));
	setup();
	replace_program(ROOM);
}

