//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
һ��һ��һ��һ������������������ƺ��������ݵ���λ�����ȷ��ЩŮ
�������������ű�һ��ϸ���Ĵ���Ѫ�ȵ�Ƥ��ȴ�ƻ����������������ա�
LONG );
	set("exits", ([
		"west"  : __DIR__"neiyuan1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

