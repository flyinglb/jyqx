// dingduan.c
inherit ROOM;

void create()
{
        set("short", "��ܶ���");
        set("long", @LONG
����������ܵĶ���������������Կ����������ҵ����������
���߰׹����⣬ȷʵû��ʲôֵ���㻳�ɵĶ��������㷢����ܵĶ�
���ǳ������ʵ�����һ����
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "down" : __DIR__"mishi",
        ]));
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"obj/hongchou" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

