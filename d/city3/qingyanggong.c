// Room: qingyanggong.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���������µ�һ����ۡ�������ľ��涣��ڸ�ͤͤ���е�ʿ��
����ȥ��û�˵ÿ����㣬��û�˽Ӵ��㡣����õ�һ�ֿ��ɵ�ʧ�䡣
LONG );
	set("exits", ([
		"northeast" : __DIR__"westroad1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
