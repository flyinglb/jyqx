//jiudian.c

inherit ROOM;

void create()
{
        set("short", "�Ƶ�");
        set("long",
             "������һ�Ҷ�����ɫ�ľƵ꣬���ڵش�������ɽ���£�\n"
         "�Ƶ���Թ�Ӧ��ζʳƷ�������⡣�����ԭ���Ͷ���������\n"
         "�ʣ����ԾƵ�������¡���Ƶ껹��Ӫ��ɢװ�Ƶ�ҵ��\n"
        );
        set("exits", ([
                "south" : __DIR__"xijie",
        ]));
	set("objects",([
		__DIR__"npc/xiaoer" : 1,
	]));
//        set("no_clean_up", 0);
        set("resource/water", 1);
        setup();
        replace_program(ROOM);
}





