//Room: /d/foshan/yingxionglou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","Ӣ��¥");
	set("long",@LONG
��¥�����νྻ�����п������κ��ݣ�ʮ���Ǹ��̴�֡���ɽ
�ش���ͨҪ�أ�����Է����˻��治�١�
LONG);
	set("objects", ([
	    __DIR__"npc/fengqi": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"street4",
	    "south"  : __DIR__"majiu",
	    "up"     : __DIR__"yingxionglou2",
	]));
	setup();
	replace_program(ROOM);
}

