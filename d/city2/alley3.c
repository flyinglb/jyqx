inherit ROOM;

void create()
{
	set("short", "������ͬ");
	set("long", @LONG
����һ��ʮ��Ƨ����С��ͬ����������һ�ҿ͵꣬����ԼԼ
������֮����������Щ��ԥ��Ҫ��Ҫ��ȥ��һ���أ�������ʲ
ôΣ�հɣ������߿��Գ���ͬ��
LONG );
        set("outdoors", "city2");
	set("exits", ([
		"southeast" : __DIR__"kedian1",
		"northeast" : __DIR__"alley2",
	]));
	set("objects", ([
                 "/d/village/npc/dipi" : 1,
                 "/d/city2/npc/punk" : 1,
	]));
//	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

