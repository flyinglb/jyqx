//ROM

inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long",
             "������һ�鲻С�Ĺ㳡���������ũ��ɹ�Ĺ��������\n"
         "������ɽׯ���������м�Сũ�ᣬ�����п�˵أ����Ϸ���һ\n"
         "��С�š�\n"
        );
        set("outdoors", "baituo");
//        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"nongshe",
//                "west" : __DIR__"caide",
                "northup" : __DIR__"shijie",
                "northwest" : __DIR__"shanlu",
                "southeast" : __DIR__"bridge",
        ]));
        set("objects",([
		__DIR__"npc/kid" : 2,
	]));
        setup();
        replace_program(ROOM);
}
