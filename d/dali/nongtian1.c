//Room: /d/dali/nongtian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ũ��");
	set("long",@LONG
һСƬ��ɽ���µ������￪�ѳ�����ũ�����Ϫ������ֲ��ˮ
����̨������ܴ�̶�������ũҵ������ũҵ��ȴ�������Ǹ�Ů����
�Ӵ�ר˾���ԺͲ��㡣
LONG);
	set("objects", ([
	   __DIR__"npc/nongfu1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"wuding",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

