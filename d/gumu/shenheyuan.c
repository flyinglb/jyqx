// shenheyuan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���ԭ");
        set("long", @LONG
�˴�λ�����ɽ�в��Ĵ仪ɽ������������ȥ��ֻ��һƬ̹����
��Ĵ�ƽԭ������Ⱥɽ֮�䡣��˵�̳�ĩ�꣬�������ʱ���������
��ʱ�����ݶ�ȱ���ڴ˻�����Ϻ�֮���������������������Ϊ���
ԭ�������Ϻͱ��ϸ���һƬ���֡�������һ���ż���
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "west"      : __DIR__"foyezhang",
                "north"     : __DIR__"shulin7",
                "southeast" : __DIR__"shulin8",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/seller": 1,
        ]));

        setup();
        replace_program(ROOM);
}
