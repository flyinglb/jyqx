#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�������鷿");
	set("long", @LONG
�����ǿ������鷿�������������������ضѷ��źܶ��顣�������ϻ���
һЩ�ҳ�����Ȼ�Ǻܾ�û�ж����ˡ��������ļ�����������ȴ���Ե�������
͸��������ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"neitang",
	]));
	set("objects", ([
		"/d/city2/npc/kang" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

