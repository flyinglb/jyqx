//Room: /d/dali/heisenlin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɭ��");
	set("long",@LONG
ӭ��һ��Ƭ��ѹѹ��ɭ�֣��ߴ�Ĺ��ɲ������������һ��
�������������������Щ�ر�
LONG);
// ��ٹ� here.
// wait to be done in future.
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"      : __DIR__"dasenlin",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

