// Room: /d/xiangyang/westroad2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���ڴ��");
	set("long", @LONG
����һ����ʯ�̾͵Ĵ�֡�������ʮ�ֽֿڡ�����������
��������һ���ܸߵĲ�¥��������һ�¸��ź�ɫ�����ߵĸ�ǽ��
�����ǹ�����Ժ�����������������¿���һ����꣬��˵����
���򵽺ܺõ��顣
LONG );
        set("outdoors", "xiangyang");

	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"shudian",
		"south" : __DIR__"westroad1",
		"north" : __DIR__"jiekou1",
	]));
	setup();
	replace_program(ROOM);
}

