//Room: /d/quanzhou/westbridge.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���ŵ���");
	set("long",@LONG
����Ȫ�������һ�����ţ��Ӱ��Ž��������ĳ�¥����������
������άϵ���ճ����µ���������𡣹������������߿ɴ����Ϲ�
����
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : "/d/foshan/road14",
	    "east"  : __DIR__"ximen",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

