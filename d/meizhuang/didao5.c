// didao5.c
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
            "north" : __DIR__"lingmu",
            "south" : __DIR__"didao4",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

