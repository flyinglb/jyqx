//lhqdating.c
inherit ROOM;

void create()
{
        set("short", "�һ������");
        set("long", @LONG
�������һ���Ĵ��������к�����չ����ǹӳѪ��������³�ñ��
����ӵס�һ�������ʹ��Ȼ��
LONG);
        set("exits", ([
                "west" : __DIR__"lhqyuan",
        ]));
        set("objects", ([
                __DIR__"npc/xinran": 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
