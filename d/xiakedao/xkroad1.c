// Room: /d/xiakedao/xkroad1.c ����ɽ��
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����������һ��ɽ�ڡ�������Ƿ�ɽ�ˣ������Ǻ�ب���Ϲ㶫
�����롣����������ȣ����������쳤������ҲԶ����ԭ�ˡ�
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"northup" : "/d/henshan/hsroad9",
		"south"   : __DIR__"xkroad2",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

