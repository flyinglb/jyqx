// Room: /d/mingjiao/midao11.c
// Date: Java 97/04/9

inherit ROOM;
#include <room.h>;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��СС��������Χ����ʯ�ڣ���Ϊ��Ӳ����������ʲô
�书�ܴ��Ƶġ�ʯ�������ֲ�����ָ��˳��ʯ���������ź�����Χ��
ʯ�š�
LONG );
	set("exits", ([
		"south" : __DIR__"midao7",
		"north" : __DIR__"midao3",
		"east"  : __DIR__"midao12",
		"west"  : __DIR__"midao10",
	]));
	set("no_clean_up", 0);
	set("no_drop", 1);
	setup();
        create_door("south", "ʯ��", "north", DOOR_CLOSED);
        create_door("north", "ʯ��", "south", DOOR_CLOSED);
        create_door("east",  "ʯ��", "west",  DOOR_CLOSED);
        create_door("west",  "ʯ��", "east",  DOOR_CLOSED);
}
