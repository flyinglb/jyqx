//Room: /d/dali/yongdao2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��");
	set("long",@LONG
���������������������������ܵĲ�����ľ�����͸����Ҷ��
�ڵ����������ǰߵ㡣ʯ������·�����࣬��������̲ݣ���׺��
һ�ǰ���С������Χʮ�ְ�����ż���������
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"neitang",
	    "east"       : __DIR__"chahua8",
	    "southwest"  : __DIR__"yongdao1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

