// Room: /shaolin/jiulou2.c
// YZC 1995/12/04 

inherit ROOM;
inherit F_DEALER;

void create()
{
	set("name", "ӭ��¥");
	set("short", "ӭ��¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������
�߳Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥����
����ֻ�����Ŀ�������������һ�غ�ˮ���̲������������ǳ�ɽ���롣
ǽ�Ϲ��ż۸�����(paizi)��
LONG );
	set("item_desc", ([
		"paizi" : "����ר���ϵ����롣\n",
	]));
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

