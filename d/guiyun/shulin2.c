// Room: /guiyun/shulin2.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������߰�����ֻ������ͷ���ϴ���һЩ�����������ż����
ï�ܵ�Ҷ��͸����һ�߹������Ҷ�ڷ��衣��ľ���õ���ζ�����ᴫ
��Ұ�޵�Х��ʹ�˲�����ԥ��ǰ���ĽŲ���
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"shulin3",
		"northwest" : __DIR__"shulin1",
		"west"      : __DIR__"shulin5",
	]));
	set("objects", ([
		__DIR__"npc/gaosan" : 1,
		__DIR__"npc/fengliang" : 1,
	]));
	setup();
	replace_program(ROOM);
}
