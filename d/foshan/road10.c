//Room: /d/foshan/road9.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ������
�棬��λ��·Ҫʮ��С�ġ�
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
            "north" : __DIR__"road8",
            "south" : "/d/players/honglianjiao",
	]));
	setup();
	replace_program(ROOM);
}

