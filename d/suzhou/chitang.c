// Room: /d/suzhou/chitang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�س�ˮӳ�����������С������Ȼˮ�У����۵�ʯ����
�������ٻ���ض�����Կ�����Ϫ¥����¥�����ص�С����
��ӳ�ڻ�ľɽʯ֮�䡣������ɽ���䣬�������������գ�����
�ڡ���ľ����������������㣬������Ƣ�����£�ˮ��������
ʯ���أ��㲻��Ϊ�˾�����̾���ѡ�
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"gumujiaohe",
	]));
	set("objects", ([
		__DIR__"npc/lady1" : 1,
	]));
	setup();
	replace_program(ROOM);
}

