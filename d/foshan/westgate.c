//Room: /d/foshan/westgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ����");
	set("long",@LONG
�����Ƿ�ɽ������š������������ɹ���������������һ��
������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"street1",
	    "west"  : __DIR__"road7",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

