//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�뷿");
	set("long", @LONG
����ׯ��С������Ӥ�Ĺ뷿��������Щ���ң�������Ӥ��������������
����ơ�Ů��������������һ�㶼���٣����������֪����λС��Ҳһ���ô���
��ȹ����ڵõ������ǣ������Ǽ���ɫ����͸¶���Ļ����Ե���Ϊͻ����
LONG );
	set("exits", ([
		"west"  : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/binv" : 1,
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

