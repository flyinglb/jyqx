// Room: /d/suzhou/majiu.c
// Date: May,31 1998 Java

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
�����ų������ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ�
����ǻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ��
��Ǭ������һֱ�ź򵽿�����·����������µ���ľ���϶���
һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
	set("outdoors", "city");
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_clean_up", 0);
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		__DIR__"npc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ���ݳ�:  rideyz

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"rongcheng",
	]));
	setup();
	replace_program(ROOM);
}
