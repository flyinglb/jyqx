//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��");
	set("long", @LONG
ת���˰���ɽ��ɽ�ƺ����˺ܶ࣬ɽ��Ҳ�������ɣ���ѩ���ǵĵط���
��Ҳ���ˣ�ԶԶ��ȥ�����Կ���һЩ�һ���ʯ��ɽ��
LONG );
	set("exits", ([
		"southeast"  : __DIR__"baixiang",
		"northwest"  : __DIR__"shalu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

