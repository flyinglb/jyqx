// Room: chufang.c
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������ĳ�����������Ŵ�Բ������Χ����ż������Ρ�
�������ĵ��Ӷ��������ò͡�
LONG );
	set("exits",([
	    "west" :__DIR__"zoulang",
	]));
	set("objects",([
		"/clone/food/jitui" : 3,
		"/clone/food/jiudai" : 1,
        ]));

        set("no_fight", 1);
        setup();
	replace_program(ROOM);
}

