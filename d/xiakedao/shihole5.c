// /d/xiakedao/shihole5.c ���͵� ʯ��5

inherit ROOM;

int do_learn(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������������Щ��ͬ��ԭ��������˰�ߺ�Ļ�������֪��ʲ
�����á�����Ҳ�ǿ������ľ���ܸ٣����仨��������ȴ�Ǳ���Բ��
�Ƴ�Ů��֮�֡���Χ��Ļ�ʹ���һɫ���ơ�
LONG );
        set("exits", ([
                "out"   : __DIR__"shihole4",
                "enter" : __DIR__"shihole6",
                "north" : __DIR__"shiroom17",
                "south" : __DIR__"shiroom18",
                "east"  : __DIR__"shiroom19",
                "west"  : __DIR__"shiroom20",
        ]));
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

