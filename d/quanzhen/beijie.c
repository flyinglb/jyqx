// beijie.c ����
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������书������Ľֵ���ÿ���һʮ�壬��Ҫ���������
Щ���֮��ľۻᡣ�ֱ�����һ�Ҿ�¥��¥ǰ����һ������������
д�˸����ġ��ơ��֡�������һ���˼ҡ�����С���ڽ���Ц����
�Ż���׷��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "south" : __DIR__"zhongxin",
                "north" : __DIR__"jiulou1",
                "west" : __DIR__"minju1",
        ]));
        set("objects", ([
                __DIR__"npc/kid" : 3,
        ]));

        setup();
        replace_program(ROOM);
}
