// Room: /d/village/sroad4.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿��������
���˼Ҳ��࣬���Ҵ�����ܼ���������һ���ϱ������ʯ·����������
�������ĵĴ�ȳ��ˣ������Ǵ���Ψһ����ש�߷���
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"square",
            "south" : __DIR__"sroad3",
            "east"  : __DIR__"bighouse1",
                "west" : "/d/village/fang.c",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        setup();
        replace_program(ROOM);
}


