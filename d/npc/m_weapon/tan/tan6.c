//tan6.c

inherit ROOM;

void create()
{
	set("short", "�����Ϻ� ");
	set("long",
		"�����Ǽ����Ϻ�ˮ�� �����ܺں��������ֲ�����ָ��������һ�����⣬��ߵ�ˮ��\n"
		"���Ϻ��µ�ӿ���š���������һ�����ۡ������ƺ���һ�����⣬Ҳ��֪��Щ\n"
		"ʲô����ΧһƬ���ţ��ƺ������Ų��ɱ����\n"

	);
	set("exits", ([
		"up" : __DIR__"tan2",	
		"down" : __DIR__"tan7",
		"east" : __DIR__"tan3",
		"north" : __DIR__"tan3",
		"south" : __DIR__"tan3",
	]));
	setup();
	replace_program(ROOM);
}
