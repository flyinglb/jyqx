
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�����Ǳ����⣬�������������������ۻ����ҡ��������������𹿰���
�󵶡��������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һ
ʱ��֪����ʲô�á�
LONG );

	set("exits", ([
		"north" : __DIR__"bingyin1",
		"southwest" :  __DIR__"aobai12",
	]));
	set("objects", ([
		"/d/city/obj/changjian" : 1,
		"/d/xingxiu/obj/tiegun" : 1,
		"/d/shaolin/obj/changbian" : 1,
		"/d/city/obj/duanjian" : 1,
		"/d/city/obj/gangdao" : 2,
	]));

//	set("no_clean_up", 0);
	create_door("north", "����", "south", DOOR_CLOSED);
	setup();
//        replace_program(ROOM);
}
