//xiaolu4

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long",
	     "������һ����ɽ��С·�����ֳ�һ�������������ɽ�������ѡ�\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"dongkou",
		"southwest" : __DIR__"xiaolu3",
		"westdown" : "/d/npc/m_weapon/lianzhangshi",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 1,
	]));
//        set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
