//tan7.c

inherit ROOM;

void create()
{
	set("short", "�����Ϻ� ");
	set("long",
		"�����Ǽ����Ϻ��ף����ܺں����ģ�ͷ���Ͽ�����һ�����⣬��ߵ�ˮ��\n"
		"���Ϻ��µ�ӿ���š���������һ�����ۡ������ƺ���һ�����⣬Ҳ��֪��Щ\n"
		"ʲô����ΧһƬ���ţ��ƺ������Ų��ɱ����\n"
	);
	set("exits", ([
		"up" : __DIR__"tan6",	
		"east" : __DIR__"tan5",
		"west" : __DIR__"tan7",
		"south" : __DIR__"tan7",
		"north" : __DIR__"tan7",
	]));
        set("objects" , ([
               __DIR__"npc/fish" : 3,
	       __DIR__"item/zhenzhu" :1,	
             ]) );
	setup();
	replace_program(ROOM);
}