//Robin 2000.5.15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�ڵض��ľ�ͷ����ôһ�����ӿ������ڣ�������ʯ��ʯ��ʯ��ʯ�䣬��
�ѻ��˺ܶ��߹ޣ����濴������ˮ����ط�������������Ϊ�˱������õĲ���
֮�ء��ڿ�ǽ��ʯ����ȼ��һ֧���۴ֵĳ����������˿��Ժ�����ؿ����
����������
LONG );
	set("exits", ([
		"east"  : __DIR__"dong4",
	]));
	set("objects", ([
		__DIR__"npc/yaoqingquan" :1,
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

