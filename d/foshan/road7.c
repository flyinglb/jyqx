//Room: /d/foshan/road7.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ����������������ɽ��
����ͨ�������
LONG);
	set("objects", ([
	   __DIR__"obj/shuzhi": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "west" : __DIR__"road6",
	    "east" : __DIR__"westgate",
	]));
	setup();
	replace_program(ROOM);
}

