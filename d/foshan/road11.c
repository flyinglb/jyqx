//Room: /d/foshan/road11.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ�����ɽ��ï�ܣ������
�棬��λ��·Ҫʮ��С�ġ�
LONG);
	set("objects", ([
	   __DIR__"obj/shikuai": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "northeast" : __DIR__"road13",
	    "southwest" : __DIR__"road10",
	]));
	setup();
	replace_program(ROOM);
}

