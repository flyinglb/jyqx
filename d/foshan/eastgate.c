//Room: /d/foshan/eastgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɽ����");
	set("long",@LONG
�����Ƿ�ɽ��Ķ��š��������߾�Ҫ�뿪��ɽ��ȥ�������ˡ�
����һ��������Ĵ���Ƿ�ɽ�����Ҫ�ֵ���
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"road8",
	    "west"  : __DIR__"street5",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

