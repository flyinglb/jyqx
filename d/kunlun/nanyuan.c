//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ϴ�Ժ");
	set("long", @LONG
������ׯ��ҵ�ǰԺ��Ժǽ�߿���һЩ��������Ȼ���˼���ϰ��ġ�Ժ��
�������ò�������Ȼ���Ĳ���ïʢ����Ҳ�����˳Ծ����ˣ���Ϊ���������ߺ�
�ĵط�Ӧ�ø���������������ֲ��ġ�Ժ�Ｘ���������ڰ���ľ�ġ�
LONG );
	set("exits", ([
		"east"  : __DIR__"xiangfang",
		"north" : __DIR__"zhuwu",
		"south" : __DIR__"qianting",
	]));
	set("objects", ([
		__DIR__"npc/jiading" : 2,
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

