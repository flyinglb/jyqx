//Room: /d/foshan/southgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ����");
	set("long",@LONG
�����Ƿ�ɽ������š����������ϣ��͵����Ϻ�֮���ˡ�����
һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG);
	set("objects", ([
//	   __DIR__"npc/puren": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"street3",
	    "south"  : "/d/xiakedao/xkroad3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

