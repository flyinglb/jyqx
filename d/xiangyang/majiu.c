// Room: /d/xiangyang/majiu.c ���
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short","���");
	set("long",@LONG
��������������Ψһһ�ҳ����С���ɻ�Ǯ����������
���ط�ȥ���ܽ�Լ����������������Ϊ������----����������
֯�����Ĵ��Ѽ����ǲ��ϣ���������Ӧ������ṩ�Ƴ�����
�͸��ַ��ǲ��ϡ�
    ������������µ���ľ���϶���һ����ľ��(paizi)��
LONG);
	set("outdoors", "xiangyang");
	set("no_fight", "1");
	set("no_beg", "1");
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
		"south"  : __DIR__"northroad2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
