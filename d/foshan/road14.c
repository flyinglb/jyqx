//Room: /d/foshan/road14.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�ּ��");
	set("long",@LONG
������һ���ּ�С���������������ѡ��������Ȫ�ݳǵ�����
���ţ������Ͽɴ����Ϲ㶫��
LONG);
	set("objects", ([
	   __DIR__"obj/hua3": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : "/d/quanzhou/westbridge",
	    "southwest" : __DIR__"road13",
	]));
	setup();
	replace_program(ROOM);
}

