// /guanwai/luming.c

inherit ROOM;

void create()
{
	set("short", "¹����");
	set("long", @LONG
���ŷ��������¹���塣¹�����ֳ�֥�̷壬�������һ�ݵ��ӣ���Բ
��ǣ��������ӵ���ð����ÿ���϶������������ѩ����Ψ¹������Ȼֲ
��ïʢ����ʢ��֥�ݣ�¹���֮�����кס�ȸ������������ϣ��С�¹��
��ȣ����֥�ǡ�֮�ơ�
LONG );
	set("exits", ([
		"south"   : __DIR__"baiyun",
		"east"    : __DIR__"longmen",
	]));
	set("objects", ([
		__DIR__"npc/buck" : 1,
		__DIR__"npc/doe" : 1,
		__DIR__"npc/diao" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
