//Room: /d/dali/chufang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�������������ĳ����������и������ӣ���Χ����ż���Բ�ʣ�
�����Ƕμҵ����ò͵ĵط���
LONG);
	set("objects", ([
	    __DIR__"obj/xueli"       : 4,
	    __DIR__"npc/obj/puercha" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"tingfang",
	]));
	setup();
	replace_program(ROOM);
}

