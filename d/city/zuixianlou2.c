// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;
inherit F_DEALER;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳Ժ�
�������ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ������
��������������һ�غ�ˮ���̲������������ǳ�ɽ���룬��������Կ�����
��ȫ���İ�¹��Ժ�ĺ�ͥ��ǽ�Ϲ��ż۸�����(paizi)��
    ϲ������ڶ��ߴ��á�
LONG );
	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));
        set("no_fight",1);
	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/guidao" : 1,
                /*CLASS_D("gaibang") + "/kongkong" : 1,*/
	]));
	set("exits", ([
		"down" : __DIR__"zuixianlou",
//		"up"   : __DIR__"zuixianlou3",
		"east": __DIR__"zxlpath",
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
