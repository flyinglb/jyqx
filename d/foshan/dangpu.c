//Room: /d/foshan/dangpu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","Ӣ�۵䵱");
	set("long",@LONG
������һ�Ÿ߸ߵĹ�̨����̨�������ŵ��̵ĳ����ҵ���
�Ƿ���ү������ʮ��������û�����ֹ��£�����Ҳ�ͺܷ��ġ���̨
�Ϲ���һ��ľ����(paizi)��
LONG);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "��ƽ����\n
	sell        �� 
	buy         ��
	value       ����
",
	]));
	set("objects", ([
	   __DIR__"npc/chaofeng": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"street5",
	]));
	setup();
	replace_program(ROOM);
}

