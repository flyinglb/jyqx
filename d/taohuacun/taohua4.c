// Room: /d/taohuacun/taohua4.c

inherit ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
�����һ��ȱ����һ��塣����ĸ��ܣ�����������ɽҰ�ķ硢
ɽ��Ĵ���ζ��ɽ���ֱ�ӡ�����Ŀ��ݡ�ɽ����һ����һ�Ϫ��
��Ů�����㲻����ȥ�볾����������������Ѫ�ȡ����ĵ��ն���
��������һ�У��������һ���������ߡ�ͮ���ǽ��
LONG );
	set("outdoors", "city");
//	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/cunzhang" : 1,
	]));
	set("exits", ([
		"southdown" : __DIR__"taohua3",
		"north"     : __DIR__"taohua5",
	]));
	setup();
	replace_program(ROOM);
}
