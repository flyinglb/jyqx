// Room: /d/village/nwroad1.c

inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����һ��������С���ӣ�ϡϡ����ķֲ��ż�ʮ�������෿��������
���˼Ҳ��࣬���Ҵ�����ܼ������������м�С�������ϵ�������ģ
�����壬��������ʲ�����ˡ�
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "west"      : __DIR__"wexit",
            "southeast" : __DIR__"nwroad2",
            "northeast" : __DIR__"temple1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xxx");

        setup();
        replace_program(ROOM);
}

