//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�Խ���");
	set("long", @LONG
�����������ɵ�����ϰ�����书�����ڣ�����ν��������ʵ����һ��¶��
�ĳ��أ�ֻ��������ש�̵ض��ѡ��ⲻ�������ﻹ�ܿ�������İ�ţɽ������
����������һ�����͵���أ��������е��Ӵ�ס���Ǳߡ�������һ������С
Ժ����ȥ�������˵����پӡ�
LONG );
	set("exits", ([
		"south"  : __DIR__"sanshengju",
		"north"  : __DIR__"tieqin",
		"east"  : __DIR__"bingqiku",
		"westdown" :  __DIR__"qipan",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 5,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

