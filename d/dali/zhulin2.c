//Room: /d/dali/zhulin2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����");
	set("long",@LONG
����һ��Ƭï�ܵ����֣�������ɽ���Ǹ�ï�ܵ���Ҷ�֣�������
�ࡣ�о����̨�������������������ס����£���׽�á�¹��С�ޣ�
�������������ɽ��׽��Щ�����ޡ�
LONG);
	set("objects", ([
	   __DIR__"npc/lieshou": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"hexi",
	]));
	setup();
	replace_program(ROOM);
}

