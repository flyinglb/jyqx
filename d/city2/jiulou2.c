
inherit ROOM;
inherit F_DEALER;

void create()
{
	set("name", "ȫ�۵¾�¥");
	set("short", "ȫ�۵¾�¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������
�߳Ժȱ������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�����ǽ�Ϲ��ż۸�
����(paizi)����վ��¥���������ǣ�ֻ�����Ŀ�������
LONG );
	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		"/d/city2/npc/cheng":1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
