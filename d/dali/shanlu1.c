//Room: /d/dali/shanlu1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ɽ·");
	set("long",@LONG
�����ڴ���ɽ���һ����·�ϡ��˼�����������ڣ��������ߣ�
��ɽ����Խ�ƽ��������ɼ���ѩ��������ظ�ԭȺɽ������һ·��
Խɽ��ֱͨ�����ϴ�������ɽ����Щ�����˵Ĵ��䡣
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northup"    : __DIR__"wunong",
	    "south"      : __DIR__"jianchuankou",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

