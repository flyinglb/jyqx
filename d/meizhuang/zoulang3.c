// zoulang3.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ȵ��������ƺ��͵��˾�ͷ�������ȵ���һͷ����������շ�
����ζ�������������㣬�ߵ������Ҳ���ܲ������������������
�����ջ�ֻ�мӿ�Ų���ȥ���������� 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"chufang",
            "south" : __DIR__"zoulang2",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

