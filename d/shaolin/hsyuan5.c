// Room: /d/shaolin/hsyuan5.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����Ժ�岿");
	set("long", @LONG
������ɮ������ʳ��ӵĵط�����ǽһ����ż���ľ������
���̵�����ϯ����ͷ���Ŵ�������������غ��䣬ɮ����ȫ����
ʵ���ڹ�������������������ķ��ż������ź�ľ�㡣
LONG );
	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"zhulin5",
		"south" : __DIR__"hsyuan4",
		"north" : __DIR__"hsyuan6",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-ming" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

