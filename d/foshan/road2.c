//Room: /d/foshan/road2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ������ǹ����ˡ�����ɽ
��ï�ܣ�������棬��λ��·Ҫʮ��С�ġ�
LONG);
	set("objects", ([
	   __DIR__"obj/hua1": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"road1",
	    "east"  : __DIR__"road3",
	]));
	setup();
	replace_program(ROOM);
}

