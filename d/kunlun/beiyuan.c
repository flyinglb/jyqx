//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����Ժ");
	set("long", @LONG
���Ǳ�ׯ��ҵĵ�ǰԺ��Ժ���������ǹ�����ע����������ÿһ���ˣ���
��Ҫ���˳Ե���Ժ�������˼���������ͣ��һ�ܶ�����������Ժ�ӱ�����
һ�������ķ��ӡ���������Ҳ����һ���᷿������Ժ�価���Ϸ����������
���ط��ܲ�Э����
LONG );
	set("exits", ([
		"east"  : __DIR__"dxfang",
		"west"  : __DIR__"xxfang",
		"north" : __DIR__"zhengfang1",
		"south" : __DIR__"zhuwu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

