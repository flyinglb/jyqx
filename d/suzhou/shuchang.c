// Room: /d/suzhou/shuchang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�鳡");
	set("long", @LONG
���߽��鳡�����������������ֵģ������ﶼ������ģ�
����ǰ����һλ˵��������������ȥ����ʮ�꣬��������һ��
��壬���ھ۾������˵������--����ҽ�������Ҳ�𽥱���
������������������е����ǲ�ʱ�ķ�����̾�ͺȲ�����ʱ��
ʱ��ͭ��������ȥ��
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"xidajie2",
	]));
	set("objects", ([
		__DIR__"npc/gongzi": 1,
	]));
	setup();
	replace_program(ROOM);
}
