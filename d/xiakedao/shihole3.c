// /d/xiakedao/shihole3.c ���͵� ʯ��3

inherit ROOM;

int do_learn(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ӭ��ɼ��ĸ�������֡�ˮ��к�ء����������ϡ����г����ݻ���
��׵Ĵ���ʯש�����������ˡ�������¯�������ƣ������Ů������
������ϡ�Ǻ�����լһ�㡣
LONG );
        set("exits", ([
                "out"   : __DIR__"shihole2",
                "enter" : __DIR__"shihole4",
                "north" : __DIR__"shiroom09",
                "south" : __DIR__"shiroom10",
                "east"  : __DIR__"shiroom11",
                "west"  : __DIR__"shiroom12",
        ]));
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

