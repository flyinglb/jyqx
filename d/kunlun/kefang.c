//Robin 2000.5.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","�ͷ�");
	set("long", @LONG
����ͷ������ס�Ŀ��˲��������˵Ŀ��ˣ�һ�������ڵ��Ӽ�������̽
��ʱס�ģ�������ط��ش�ƫƧ���������˵ļ���Ҳ���������ġ����������
������Ϊ��Ů������͵��ĺõط���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaoyuan2",
	]));
	set("sleep_room", "1");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
