// Room: /d/xiangyang/yaopu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
ҩ�̲���ȴ�쳣�����ࣻ�����ǹ�̨����̨�����Ǹ���
���Ӽ��ٸ�С������һһ�ú�ֽ����ҩ�ĵ����ƣ������ݶ���
ǽ������һ��ڵ׽��ֵ��Ҷд�š����ֻش��������¼���
������ڷּ�ո��չ����Ĳ�ҩ������һ��С�������������
�ű�īֽ�⣬��������һλ�����С�һ�ɴ̱�ҩζ����������
���䡣
LONG );
	set("exits", ([
		"north" : __DIR__"eastjie1",
	]));
	set("objects", ([
		"/d/city/npc/huoji" : 1,
	]));
	setup();
	replace_program(ROOM);
}
