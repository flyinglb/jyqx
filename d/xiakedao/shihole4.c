// /d/xiakedao/shihole4.c ���͵� ʯ��4

inherit ROOM;

int do_learn(string arg);
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�˶�����ȴ�ִ���ͬ��ȴ����������ɽһ�㡣ֻ��һɫ�첼�
ᣣ���֧�ִ�ĺ�������Ľǡ�һ��վ��������״󺺣������䵶��
�����Ϻ�ӣ�ʹ������д������۽���κ���壺��������项��
LONG );
        set("exits", ([
                "out"   : __DIR__"shihole3",
                "enter" : __DIR__"shihole5",
                "north" : __DIR__"shiroom13",
                "south" : __DIR__"shiroom14",
                "east"  : __DIR__"shiroom15",
                "west"  : __DIR__"shiroom16",
        ]));
        set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

