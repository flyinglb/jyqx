//Room: /d/foshan/road4.c
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
	   __DIR__"npc/snake": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "southwest" : __DIR__"road3",
	    "southeast" : __DIR__"road5",
	]));
	setup();
	replace_program(ROOM);
}

