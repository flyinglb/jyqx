// Room: /t/wanjiegu/tunnel1.c

inherit ROOM;

void create()
{
        set("short", "�ص�");
        set("long", @LONG
�ص�����ߺڰ����������ǣ�һ��ùζ�˱Ƕ������ص���ʯ̨
���쳣�ֲڣ�������ǽ�ϲ�ʱ����ˮ�ε������ϡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"tunnel2",
            "out" : __DIR__"tree_hole",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
