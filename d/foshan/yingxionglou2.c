//Room: /d/foshan/yingxionglou2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","Ӣ��¥");
	set("long",@LONG
��¥�����νྻ�����п������κ��ݣ�ʮ���Ǹ��̴�֡�����
���Ը��ɽ��ȫ����
LONG);
	set("objects", ([
	    __DIR__"npc/pang": 1,
	    __DIR__"npc/shou": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"yingxionglou",
	]));
	setup();
	replace_program(ROOM);
}

