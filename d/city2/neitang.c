
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ǿ������ã�һ���������ں�Ѿ�������졣�ϱ��ǿ���
��Ժ���������鷿��������һ�����á�
LONG );
        set("outdoors", "city2");
//	set("no_clean_up", 0);
	set("exits", ([
  		"north" : "/d/city2/shufang",
  		"south" : "/d/city2/kang3",
  		"west" : "/d/city2/fotang",
	]));
	set("objects", ([
  		"/d/city2/npc/puyi": 1,
  		"/d/city2/npc/yahuan": 2,
	]));
	setup();
	replace_program(ROOM);
}
