//Room: /d/dali/tusiyishi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
���������������裬���³����ŵ����桢ì��ꪵȱ����������Ĵ�¥��
�£�������ʵ�����ÿ���ǰ�����һ�������������������Ϣ��
LONG);
	set("objects", ([
	   __DIR__"npc/datusi": 1,
	   __DIR__"npc/zutouren": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"tusimentang",
	]));
	setup();
	replace_program(ROOM);
}

