//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
����������������������ɽ������ΪӦ�õ�������ɽ����ߴ��ˣ�����
���������һ����Ʋ��Զ������������ɽ�壬���ں�Զ�ˣ��Ѿ�������
������Щɽ�ĸ߶Ⱥ������������µ�ɽ·ȴ�ƺ��Ѿ����˾�ͷ����ǰ��һ��
�������׵����¡�
LONG );
	set("exits", ([
		"southdown"  : __DIR__"jilu2",
        ]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
