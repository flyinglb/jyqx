//Room: /d/dali/feilihu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��������");
	set("long",@LONG
��վ���������ı��������߲�Զ����ϲ�ݳǡ��˺����󣬵���ˮ
�峺�������У�����̨�Ĵ��������ں��ϲ��㡣��֮�ϺͶ���
��ɽ�϶���̨�Ĵ����е�·�ƺ�������ͨ���ϱߡ�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"xizhou",
	    "east"       : __DIR__"luwang",
	    "southeast"  : __DIR__"feilihueast",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

