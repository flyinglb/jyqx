//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��԰");
	set("long", @LONG
�����������˼���լ�е�һ����԰��԰������һЩϣ��ŹֵĻ��ݡ���԰
�ļ����ŷֱ�ͨ���̫��ļ������˵�ס����
LONG );
	set("exits", ([
		"south" :  __DIR__"zoulang1",
		"north" :  __DIR__"zhengfang",
		"west"  :  __DIR__"cefang",
	]));
	set("objects", ([
		__DIR__"npc/binv" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","kunlun");
	setup();
	replace_program(ROOM);
}

