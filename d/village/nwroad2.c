// Room: /d/village/nwroad2.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿��������
���˼Ҳ��࣬���Ҵ�����ܼ��������ϱ߾��Ǵ������ĵĴ�ȳ��ˣ���
���Ǽ��񷿡�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
            "northwest" : __DIR__"nwroad1",
            "southeast" : __DIR__"square",
            "southwest" : __DIR__"nwhouse",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        setup();
        replace_program(ROOM);
}


