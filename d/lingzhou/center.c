// Room: /lingzhou/center.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���������Ķ������ݵ����Ĺ㳡��Ҳ��������ֵĽ��㴦��������
�ʳǣ���������ҵ�����ضΣ���������ͨ������������Ӫ���������ź�
���������ǵĸ��ڡ������������������ʼ�ɢ�غ���ҵ���ģ�Ҳ����
��ͨ����ԭ�ıؾ�֮�ء���ɫ�˵�������������˻�˺������ַǷ�����
���յ������յġ�Ҫ���ġ��󸹱��Ĳ���������Я����������ݵ���
���ǣ�ż��Ҳ����ɫ�ҴҵĽ�����ʿһ�ζ�����
LONG );
	set("exits", ([
		"south" : __DIR__"nandajie",
		"north" : __DIR__"beidajie",
		"east"  : __DIR__"dongdajie",
		"west"  : __DIR__"xidajie",
	]));
	set("objects", ([
		__DIR__"npc/duan" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	setup();
	replace_program(ROOM);
}

