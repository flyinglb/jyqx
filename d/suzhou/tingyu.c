// Room: /d/suzhou/tingyu.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ݳ��ڵ�һ��Ψһ��һ������ˡ��������Ÿ�
�ָ������鼮��ʲôС˵�������������������������������
�书�����ȵȵȵȡ�ֻ�뻨�������ӾͿ�������Ҫ���顣
LONG );
//	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"nandajie2",
	]));
	setup();
	replace_program(ROOM);
}

