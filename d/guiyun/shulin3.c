// Room: /guiyun/shulin3.c
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
		"east"      : __DIR__"shulin4",
		"northwest" : __DIR__"shulin2",
	]));
	set("objects", ([
		__DIR__"npc/fanyifei" : 1,
		__DIR__"npc/luzhengping" : 1,
	]));
	setup();
	replace_program(ROOM);
}
