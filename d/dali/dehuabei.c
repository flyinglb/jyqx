//Room: /d/dali/dehuabei.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��گ�»���");
	set("long",@LONG
��گ���߷��ڴ����챦��䣬ͬ�������ν�ս�����ƾ�ʮ����
���󣬸��߷��л��⣬Ϊһʱ���񣬡����ǰ�ǣ��������񡱡����ǣ�
������ʰ�ƾ�������ʿ����������֮���Դ���ɡ���ͬʱ������׫�ģ�
����챦ս���Ľ���ͽ������ﲻ���Ѷ����ƵĿ��ԣ������̳ɾ�
�������챦ʮһ����������̫�ͳǹ����⡣
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"road3",
	    "south"  : __DIR__"taihecheng",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

