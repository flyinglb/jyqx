// Room: /t/wanjiegu/riverside2.c

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
        set("exits", ([ /* sizeof() == 3 */
            "southeast" : "/d/dali/road3",
            "southdown" : __DIR__"riverside1",
            "northdown" : __DIR__"riverside3",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
