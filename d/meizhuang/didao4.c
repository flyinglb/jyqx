// didao4.c
inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
��һ�����ӭ����ŵ�һ�ɸ��õ�������ζ����������ǰ���
�����У����ֿ�����ϣ�����㲻����ʼ�ӿ�Ų����뿴�����ﵽ����
Щʲô������ 
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"didao5",
            "up" : __DIR__"didao3",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

