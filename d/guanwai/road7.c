// /guanwai/road7.c
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ�������������
������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬Ϊƽ̹��
��������˼�����͵����ߡ���Х�����Ŀ�綳����ֱ����¡�
LONG );
	set("exits", ([
		"north" : __DIR__"road8",
		"south" : __DIR__"road6",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

