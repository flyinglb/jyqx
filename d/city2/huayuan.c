
inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
����һ��С��԰����Ȼ������̫�࣬ȴʮ��������࣬����ƽ��
����������ɨ����԰������һ����á�
LONG );
        set("outdoors", "city2");
	set("no_clean_up", 0);
	set("exits", ([
  		"east" : "/d/city2/kang3",
  		"north" : "/d/city2/fotang",
	]));
	setup();
	replace_program(ROOM);
}
