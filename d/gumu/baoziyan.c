// baoziyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ·������ɽ·��Խ��Խ�ա�ֻ����ͺͺ��ɽ·�����Ծ��ǹ�ʯ��
��������������Ԩ���첻���ס�ǰ����Զ����һ���ʯ������������
�����ҡ��ٿ����ۣ�����������������֣�����һ�����˱��Ÿ�����
�㣬ϸ�ĺǻ������Ϻ�������һƬ���֡�
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "west"      : __DIR__"shulin8",
                "south"     : __DIR__"shulin9",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/chen": 1,
        ]));

        setup();
        replace_program(ROOM);
}
