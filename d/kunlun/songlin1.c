//Robin 2000.5.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ѩ����ɼ��");
	set("long", @LONG
��������������Ⱥɽ�����Կ�������������ɼΪ����ɽ�֣���ɽ�����Ӻ�
������ɽ��ȫ��ͬ�������ɽ��Զ����������һ����̬���ʹ�������������ɽ
�������������������Ұ����ߴ���ɽ������������ϵļ�̣�һ����ֱ��
�����������кܶ�ɽ��һ��͸���û��ɽ�¶��·����츫��������һ��ƽ����
ֱ��
LONG );
	set("exits", ([
		"northeast"  : __DIR__"shanlu10",
		"west"  : __DIR__"songlin2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}

