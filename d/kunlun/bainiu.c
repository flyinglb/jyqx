//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ţɽ");
	set("long", @LONG
����ɽ��ƽ������Զ���ĳ�ɽ���������죬ɽ���ϳ��Ĳ��Ǹߴ������
ɼ������һ�ָ߽������Ļƶ����׵�Ұ�ݣ������Щ�в������İ�ɫС������
���������濴ȥ���ɼ�ʮ������ש�߷��������м������翣��������������
ɽ����һ�����䳡ģ���Ŀտ��ء�������ɽ֮���ɽ������һƬũ�
LONG );
	set("exits", ([
		"northdown"  : __DIR__"shantian1",
		"southdown"  : __DIR__"shanlu6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
