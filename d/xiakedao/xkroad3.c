// Room: /d/xiakedao/xkroad3.c
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "ƽԭС·");
	set("long", @LONG
�������齭�����޵�ƽԭС·�ϡ��˴��������֮�磬�л���֮
��������������ģ���紾�ӡ�
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"north"   : "/d/foshan/southgate",
		"south"   : __DIR__"xkroad4",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

