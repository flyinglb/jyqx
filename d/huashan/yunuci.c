// yunuci.c

inherit ROOM;

void create()
{
        set("short", "��Ů��");
	set("long", @LONG
��Ů���﹩��ĵ�������λ��Ů������಻ͬ��˵�����������ܿ���
��ֻһ������ʯ�����д�ʯ����һ�����ݣ�������ˮ��̣�������Ů
��ϴ���裬��ˮ���겻�ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"yunu",
        ]));
        set("resource/water", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
