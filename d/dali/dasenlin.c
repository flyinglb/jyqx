//Room: /d/dali/dasenlin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ɭ��");
	set("long",@LONG
��ȥ��������ɽ���ʹ�ɭ�֣������Ѿ���ľï���˼�
�����ˣ������Ǵ�����ԭ�Ĺٵ���·��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"   : __DIR__"dianchi",
	    "north"   : __DIR__"heisenlin",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

