//Room: /d/foshan/youtiaopu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ձ�������");
	set("long",@LONG
����ձ����������¿��ŵġ����治�����������һ����ը
����һ����¯��
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"street4",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

