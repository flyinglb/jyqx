//Room: /d/dali/jingzhuang3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
��������������������֮������������һ�顣ʶ��ν����
��۹���������Ϊ�ز��������������Ŀ�Ͱ�����̾�ϸ������������
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "up"    : __DIR__"jingzhuang4",
	    "down"  : __DIR__"jingzhuang2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

