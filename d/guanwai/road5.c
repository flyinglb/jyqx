// /guanwai/road5.c
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ�������������
������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬Ϊƽ̹��
��������˼�����͵����ߡ�·�����˽���ϡ������������Ҳ���������ˡ�
LONG );
	set("exits", ([
		"north"     : __DIR__"road6",
		"southwest" : __DIR__"road4",
	]));
	set("objects",([
		__DIR__"npc/erhu" : 1,
		__DIR__"npc/sihu" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

