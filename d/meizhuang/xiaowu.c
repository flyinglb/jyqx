// xiaowu.c
inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
��������С���Ժ󣬷������ﾹȻ��������Ĳ��ܴ�����
��Ȼ����˵�ǽ�̻Իͣ��������������Ƶ����������������Σ�����
�磬��������......����ʤ����ǽ�Ϲ���һ����������һ�߰���
���١�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "out" : __DIR__"xiaoyuan",
        ]));
        set("objects", ([ /* sizeof() == 2 */
            __DIR__"npc/huangzhong-gong" : 1,
            __DIR__"obj/wall" : 0,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "meizhuang");

        setup();
        replace_program(ROOM);
}

