//Room: /d/dali/shijing.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ʯ��");
	set("long",@LONG
�����ڴ������������е�ʯ���ϡ�·�߳�ľ���죬΢��ϰϰ��ʮ
����ˬ��·����һ������͸����С����ˮ�����㣬ӳӰ��䡣����ͨ
���������������Ǹ���԰��
LONG);
	set("objects", ([
	   __DIR__"npc/xianhe": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"tingyuan",
	    "west"  : __DIR__"wfdating",
	]));
	setup();
	replace_program(ROOM);
}

