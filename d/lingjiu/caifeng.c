//ROOM: caifeng.c

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long",@LONG
���ǡ����չ����Ĳ÷��ҡ�����Ů��Χ����һ�飬�������ߣ�����Ů
�죬�ѵ�������Ϊ���Ժ���һ�����ż��� 
LONG  );
        set("exits", ([
		"south" : __DIR__"changl10",
        ]));
        set("objects",([
		__DIR__"npc/fumy" : 1,
       	]));
//	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
