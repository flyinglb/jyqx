//Room: /d/dali/luwang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","³����");
	set("long",@LONG
���������Ჿ��³�������Ჿ��̨�ģ��������и�����Խ�ݡ�
����һ������ɽ���ϵ�С�򣬶���ͱ����Ǹ��ʵ�Ⱥɽ������������
�����ɼ���ׯ�ͳ���
LONG);
	set("objects", ([
	   __DIR__"npc/tshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"    : __DIR__"feilihu",
	    "east"    : __DIR__"yulin",
	    "south"   : __DIR__"shuitian",
	    "north"   : __DIR__"zhulou3",
	]));
	setup();
	replace_program(ROOM);
}

