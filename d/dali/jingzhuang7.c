//Room: /d/dali/jingzhuang7.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���߲�");
	set("long",@LONG
�����Ǿ����Ķ�����Բ���ζ���������񷡣��������������
������ʿ�ȡ�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"jingzhuang6",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

