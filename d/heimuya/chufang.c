// Room: chufang.c
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǻ�ľ�µĳ�����������Ŵ�Բ������Χ����ż������Ρ�
������̵ĵ��Ӷ��������ò͡�
LONG );
	set("exits",([
	    "west" :__DIR__"chengdedian",
	]));
	set("objects",([
		"/clone/food/jitui" : 6,
		"/clone/food/jiudai" : 2,
        ]));

        set("no_fight", 1);
        setup();
	replace_program(ROOM);
}

