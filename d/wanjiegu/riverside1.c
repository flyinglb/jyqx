// Room: /t/wanjiegu/riverside1.c

inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
�������׽��ߵ�һ��С·����ˮ���ϣ������汼�ڶ���������
�ϲ�ʱ���������ĺ��������뽭��ĺ�Х���γ�һ�����˵Ľ�����
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 1 */
            "northup" : __DIR__"riverside2",
        ]));
        set("objects", ([
            __DIR__"npc/duck" : 2,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
