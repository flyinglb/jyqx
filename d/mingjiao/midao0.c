// Room: /d/mingjiao/midao0.c
// Date: Java 97/04/9

inherit ROOM;
#include <room.h>;
void create()
{
	set("short", "��");
	set("long", @LONG
����һ��СС��������Χ����ʯ�ڣ���Ϊ��Ӳ����������ʲô
�书�ܴ��Ƶġ������ʯ��������Ȼ���ϣ���ֻ�й�����ǰ��
LONG );
	set("exits", ([
		"north" : __DIR__"midao1",
	]));
	set("no_clean_up", 0);
	setup();
        create_door("north", "ʯ��", "south", !DOOR_CLOSED);
}
