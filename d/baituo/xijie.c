//xijie

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
             "������С������֡������и��Ƶ꣬��ǰ�����Ÿ߸ߵ���\n"
         "�ˣ�һ���಼����ӭ��Ʈ�����ӡ�����ɫ�Ĵ��֡��ơ���\n"
        );
        set("outdoors", "baituo");
        set("exits", ([
                "west" : __DIR__"bridge",
		"east" : __DIR__"dongjie",
                "north" : __DIR__"jiudian",
        ]));
	set("objects",([
		__DIR__"npc/man" : 1,
                __DIR__"npc/snaker"  :1,
	]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
