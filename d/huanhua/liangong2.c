// liangong2.c

inherit ROOM;

void create()
{
	set("short", "С���");
	set("long", @LONG
  �߽��������ӳ����������һ�����ʵġ��ɻ�ˮ��ͼ��������һ�䲢��̫�󷿼䣬
�Եúܾ��ɱ��¡����ⲻʱ��������Ʈ��������������С�����ɹ�������
LONG
	);
        set("exits", ([ 
		"north" : __DIR__"huayuan1", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
