//Room: /d/dali/chahua7.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨԰");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨
԰�У�������һ��Сɽ��ɽ�������˳�����ľ�����ϳ���ί�أ�����
���ġ�������һ��ССͥԺ��������ȥ����һƬ����ǧ�졣
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"   : __DIR__"chahua6",
	    "northup" : __DIR__"chahua9",
	    "east"    : __DIR__"chahua10",
	    "west"    : __DIR__"chahua8",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

