//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ǰ��");
	set("long", @LONG
��������ׯ�ӵ�ǰ�������ڵİ���װ�ξ����Ϸ����������������һ��
�軨ͼ��ͼǰһ�ŷ����ϰ���һ�ѽ������Ե�̫ʦ��������һ�������ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"nanyuan",
		"south" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/wulie" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

