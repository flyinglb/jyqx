
inherit ROOM;

void create()
{
	set("short", "ϷԺ��̨");
	set("long", @LONG
������ϷԺ��̨������Ϸ�����ڻ�ױ���ӱ��߿�����̨��
LONG );
        set("outdoors", "city2");
	set("exits", ([
  		"west" : "/d/city2/xiyuan",
  		"northup" : "/d/city2/stage",
	]));
        set("objects", ([
                "/d/city2/npc/xizi" : 2,
        ]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
