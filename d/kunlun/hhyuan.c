//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��԰");
	set("long", @LONG
��԰��Ļ������࣬�˹���ɽʯȴ�ǲ��٣�԰�е�·���ۣ����ⲻ��Ļ�
԰�Եô���˷����������¡��ڻ�԰�����ϱ����⻨԰����һ����ɽ���ƹ�
�Ǽ�ɽ¶�����ȵ�һ�ǡ�
LONG );
	set("exits", ([
		"southwest" : __DIR__"jiashan",
		"southeast" : __DIR__"neiyuan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

