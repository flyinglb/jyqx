// Room: /d/shaolin/hsyuan2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����Ժ����");
	set("long", @LONG
������ɮ������ʳ��ӵĵط�����ǽһ����ż���ľ������
���̵�����ϯ����ͷ���Ŵ�������������غ��䣬ɮ����ȫ����
ʵ���ڹ�������������������ķ��ż������ź�ľ�㡣
LONG
	);
	set("sleep_room",1);

	set("exits", ([
		"east" : __DIR__"zhulin2",
		"south" : __DIR__"hsyuan1",
		"north" : __DIR__"hsyuan3",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/hui-xiu" : 1,
	]));
	setup();
        replace_program(ROOM);
}



