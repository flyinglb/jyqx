//Room: /d/foshan/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ��������ǹ���������
���߾��Ǵ�����ĵؽ��ˡ�
LONG);
	set("objects", ([
	   __DIR__"obj/shikuai": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "northwest" : "/d/dali/road5",
	    "east"      : __DIR__"road2",
	]));
	setup();
	replace_program(ROOM);
}

