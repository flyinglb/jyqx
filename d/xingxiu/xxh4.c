// Room: /d/xingxiu/xxh4.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն�
����ͨ�����޺������������һ�����̵�ʯͷ·��
LONG );
        set("objects", ([
                __DIR__"npc/haoshou" : 1,
        ]) );
        set("exits", ([
             "southeast" : __DIR__"xxh2",
             "northeast" : __DIR__"xxh5",
             "west"      : __DIR__"xxh6",
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);

}

