// Room: /lingzhou/wangling.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
���������������ʵ۵���Ĺ��������������������Χ��ɽ��������
���ǳ��ľ�����Χ�����˲��ɴ�أ����е������Ļʵ���Ԫ껵ĸ�����
��������Ĺ��Ϊ��ΰ���������������Ƴ�������Ȼֱ���γ��Ե����ų�
�ʵۣ�������Ԫ껳��Ա�Ϊ������ڶ���������������Ĺ����쳣���
LONG );
	set("exits", ([
		"southup" : __DIR__"qingxinquan",
		"north"   : __DIR__"chiling",
	]));
	set("objects", ([
		__DIR__"npc/shiwushi" : 4,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

