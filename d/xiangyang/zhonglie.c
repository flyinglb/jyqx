// Room: /d/xiangyang/zhonglie.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ǵ���������ʮ������Ϊ������������������
ʿ�ŹǶ����������ÿ���а����ĵĺú����ⶼ��������һ
���һꡣ
LONG );
	set("no_fight", 1);
	set("no_beg", 1);
	set("no_clean_up", 0);

	set("exits", ([
		"west" : __DIR__"eastroad2",
	]));
	setup();
	replace_program(ROOM);
}
