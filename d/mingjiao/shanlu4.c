#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
����ɽ·������ʯ��·��̦�۵��࣬·������ΡΡ��·����
��������ԶԶ�ģ�ֻ��ǰ��������ϡ�����ɫ������չ����˵����
�һ����ڴ˾��أ���������������ʯ��
LONG );
	set("exits", ([
		"southdown" : __DIR__"shanlu3",
		"northup"   : __DIR__"lhqpaifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
