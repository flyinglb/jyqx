//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���پ�");
	set("long", @LONG
������������������ˡ�������������̫��������������������еķ���
�ϰ���һ���٣���˵����ʼ�桰������ʥ���������������������Ϊ��������
�õľ��������١�
LONG );
	set("exits", ([
		"south" :  __DIR__"shijian",
		"north" :  __DIR__"zoulang1",
	]));
	set("objects", ([
		__DIR__"npc/hetaichong" : 1,
	]));
	setup();
	replace_program(ROOM);
}

