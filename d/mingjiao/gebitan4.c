//gebitan4.c

inherit ROOM;

void create()
{
        set("short", "���̲");
	set("long", @LONG
��ǰ��һ���޼ʵĸ��̲��û��·�꣬Ҳû��һ�����ˣ���
�Եúܸߣ�Զɽ��ѩ����ӥ���裬������ãã���֮�ϣ����ƺ�
��·�ˡ�
LONG );
 	set("exits",([
	    "east" : __DIR__"gebitan4",
	    "west" : __DIR__"gebitan4",	
	    "north" : __DIR__"gebitan5",
	    "south" : __DIR__"gebitan3",  				
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
