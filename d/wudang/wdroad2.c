// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ�������Լ�ɼ������ݳǵĳ�ǽ���˴�������
��ȥ�����Կ���һ������
LONG );
        set("outdoors", "wudang");
	set("exits", ([
		"south" : __DIR__"wdroad3",
		"north" : __DIR__"wdroad1",
		"southeast" : "/d/guiyun/yixing",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

