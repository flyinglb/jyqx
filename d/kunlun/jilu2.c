//Robin 200.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��·");
	set("long", @LONG
�������Խ��ɽ���ɽ·��һ��ɽ���ϣ���Ȼ����һ��С·ͨ����һ��
���ߵ�ɽ�塣�����ɽ������û�ڸ��ߵ��Ʋ����ˣ���ɽ�������������޷�
���������
LONG );
	set("exits", ([
		"northup"  : __DIR__"xuanya",
		"east"  : __DIR__"jilu1",
		"west" :  __DIR__"jilu3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

