//gebitan3.c

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
	    "east" : __DIR__"gebitan2",
	    "west" : __DIR__"gebitan3",	
	    "north" : __DIR__"gebitan4",
	    "south" : __DIR__"gebitan3",  				
	]));
	set("objects",([
		__DIR__"obj/shigu":3,	
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
