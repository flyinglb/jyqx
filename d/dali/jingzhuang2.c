//Room: /d/dali/jingzhuang2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ڶ���");
	set("long",@LONG
Ϊ�������񣬸��б��飬����¡�𣬽�ڱ��֣����Ⱪ�𣬼���
����С�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "up"    : __DIR__"jingzhuang3",
	    "down"  : __DIR__"jingzhuang1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

