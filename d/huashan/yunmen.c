// yunmen.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��ɯ��ƺ���ǻ�ɽʮ���̡�ʮ���̵ľ������ǡ����š��ˡ��������
���ɾ����������µ�һ��ɽ����ʯ�̡�����֮�ڵ�С��ؾ������ƺ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "northdown" : __DIR__"shaluo",
            "southup" : __DIR__"qingke",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
