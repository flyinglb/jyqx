//Room: /d/dali/yongdao1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��");
	set("long",@LONG
���������������������������ܵ����֣��紵����Ҷɳɳ����
ʯ������·�����࣬��������̲ݣ���׺��һ�ǰ���С������Χ
ʮ�ְ�����
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast" : __DIR__"yongdao2",
	    "south"     : __DIR__"tingfang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

