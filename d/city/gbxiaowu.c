// Room: gbdixiaoshi.c
// by aji

inherit ROOM;
void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
���߽���һ��С�ݡ�����ǽ�ڶ�����������ɣ�������һ���޼ʵ����֡�
��������Ρ����̾�Ϊ���ơ���һ���˱Ƕ����Ĺ�����ζ��ȴ�Ե��������ŵ�
���׸���롣
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"gbandao"
        ]));
	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
		__DIR__"obj/zhubang": 1,
		__DIR__"obj/gourou": 1,
		__DIR__"obj/jiudai": 1,
		__DIR__"obj/jitui": 1
	]));

        set("valid_startroom", 1);
        set("sleep_room", 1);
//        set("no_clean_up", 0);
        setup();

        replace_program(ROOM);
	"/clone/board/gaibang_r"->foo();
}

