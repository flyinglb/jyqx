//Room: /d/dali/qingxi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��Ϫ��̶");
	set("long",@LONG
��Ϫ��̶����������ˮ�������ڲ�ɽ��������ʥӦ��֮�������
Ͽ���С�ɽȪ�Ҹ�ӿ��������к����Ϫ��أ�׳�����裬��������
ˮ��ʯ������̽��ӣ����׳����Ϫ��
LONG);
	set("objects", ([
	   __DIR__"npc/biaotou": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northup"   : __DIR__"dadieshui",
	    "eastup"    : __DIR__"bijishan",
	    "southdown" : __DIR__"xiaodao1",
	]));
	setup();
	replace_program(ROOM);
}

