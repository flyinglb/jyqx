// Room: /d/shaolin/hsyuan6.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����Ժ����");
	set("long", @LONG
������ɮ������ʳ��ӵĵط�����ǽһ����ż���ľ������
���̵�����ϯ����ͷ���Ŵ�������������غ��䣬ɮ����ȫ����
ʵ���ڹ�������������������ķ��ż������ź�ľ�㡣
LONG );
	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"zhulin6",
		"south" : __DIR__"hsyuan5",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-jie" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

