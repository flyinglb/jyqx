//Room: /d/foshan/street2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ���");
	set("long",@LONG
��ɽ��ֵ���ب�������ϱ���һ���ưܵ����������һ�Ҷ�
����������д�š�Ӣ�ۻ�ݡ��ĸ����֡�
LONG);
	set("objects", ([
	    "/d/city/npc/liumang": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "south" : __DIR__"huiguan",
	    "west"  : __DIR__"street1",
	    "east"  : __DIR__"street3",
	]));
	setup();
	replace_program(ROOM);
}

