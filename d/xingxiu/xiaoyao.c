// Xiaoyao.c:  the sleeping room for Xingxiu
// Jay May 13, 96

inherit ROOM;

void create()
{
        set("short", "��ң��");
        set("long", @LONG
����һ���ֲڵ�ʯ�����������˼��ų����Ĳݵ��ӡ������Ա�
��һЩ�ƾƹ��ӡ�����(wall)����Щ�ּ���
LONG );
        set("sleep_room", "1");
        set("no_fight", "1");
        set("exits", ([
                "out" : __DIR__"xxh6",
        ]));
        set("item_desc", ([
                "wall" : "�����������˵ö���֮��\n",
        ]) );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

