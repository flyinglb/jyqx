//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����ɽ·");
	set("long", @LONG
һ����ȥ�������޾��ĸ�ɽ��ɽ���Ѷ��������ľ���еͰ��Ĺ�ľ��Ҳ��
�ߴ���ɰأ�ɽ��ҲԽ���վ�������ɽ��������֮���ˣ�������Ҳ��Ʈ����
���̰����������˷ֲ����������ϻ������˼��ˡ�
LONG );
	set("exits", ([
		"westup"  : __DIR__"shanlu5",
		"eastdown"  : __DIR__"shanlu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

