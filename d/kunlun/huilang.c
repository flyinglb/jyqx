//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
һ��ľ�����ߵ�ʮ�ֳ��ȣ�һЩ��֪���Ļ����������Ѿ���ɫ�ವ�����ˡ�
���ȵ��ϱ�ͨ��һ��Ժ�ӣ����������С�������ĵط���������һ����԰��һ
�ǣ���Ի��ȵ���һ����ʯ��ɽ������ͨ����ҵ�������������һƬ�Ӳݴ���
�Ļĵء�
LONG );
	set("exits", ([
		"east"  : __DIR__"zhengfang1",
		"north" : __DIR__"jiashan",
		"south" : __DIR__"laying",
	]));
	set("objects", ([
		__DIR__"npc/binv" : 1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

