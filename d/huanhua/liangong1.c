// liangong.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ��ܴ�ķ��ݣ������ǽ�Ͽ���һ�����������ڷ�Ծ���������ơ�����
վ�����󺺣����б��žŻ��󵶡�����ĺ���������˵���Ϣ֮���ˡ�
LONG
	);
        set("exits", ([ 
		"west" : __DIR__"huayuan1", 		
]));
        set("no_fight",0);
        set("no_steal",0);
        set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
