// Room: /d/suzhou/wenmeige.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��÷��");
	set("long", @LONG
���ڵ����ʡ���������ƺ���黭��ȡ����÷���������Ҷ�
��粴���Ѷ������ǰ��ֲ�����֦÷���Է���������Ϊ��ʱ��
�����顢�滭֮����
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"zhenquting",
		"south" : __DIR__"lixuetang",
	]));
	set("objects", ([
		__DIR__"npc/lady4" : 1,
	]));
	setup();
	replace_program(ROOM);
}

