// Room: /t/wanjiegu/shan_road4.c

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ��ɽ��С·������ɽ�������������ľ�����紵������
��ɳɳ��������·����������Ӳݣ�������������������߶�����
������ԶԶ�ɼ���ѹѹһƬ��ɭ�֡�
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"entrance",
            "southup" : __DIR__"shan_road3",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
