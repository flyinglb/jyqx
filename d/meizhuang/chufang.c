// chufang.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��˳����ζ�ߵ���÷ׯ�ĳ�����һλ��ʦ��վ����̨����Ц����
�Ŀ����㣬����������һ�����ף������İѹ������ŵ�һ���ʳ���
�ȣ�÷ׯ�ĵ�����������ˣ��͵�����������λ��ʦ�ܲ��ܳԷ���һ
����˵�����Ƕ������⵽�ܾ��ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"zoulang3",
        ]));
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/chushi" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

