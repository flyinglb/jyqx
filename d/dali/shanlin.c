//Room: /d/dali/shanlin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ��");
	set("long",@LONG
������һƬï�ܵ�ɽ���У�ʱ���з������޺�����������ּ��
�����ϱ����Ĳ�����Ĵ��񾭳��������ԡ�ɽ�ֱ��治Զ����¡¡ˮ
���������д���������ϱ���һƬ���ݵĺӹ���أ��������̡�
LONG);
	set("objects", ([
	   __DIR__"npc/lieren": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"hebian",
	    "southdown"  : __DIR__"gelucheng",
	]));
	setup();
	replace_program(ROOM);
}

