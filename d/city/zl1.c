#include <room.h>
inherit CHATTING_ROOM;

void create()
{
	set("short", "���Ͽ⡪��Ҳ�");
	set("long", @LONG
������һ���������鷿�����г����������ܣ��ں���Ŀ��λ���Ϲ���һ��
���ӣ���¼���½�ӹȺ��II�и��ֵ����ϡ���
LONG );
	set("exits", ([ 
		"south" : __DIR__"shuyuan",
	]));
	set("no_fight",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
