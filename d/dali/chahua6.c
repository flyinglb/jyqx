//Room: /d/dali/chahua6.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨԰");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨
԰�У������Ǵ��̵Ĺ�ľ�������ŵ��Ǳ��������ĺ���һ���峹
��СϪ�������������С�����м���һ�轿�޵Ĳ軨��
LONG);
	set("objects", ([
	   __DIR__"obj/chahua5": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"chahua3",
	    "north"  : __DIR__"chahua7",
	]));
	setup();
	replace_program(ROOM);
}

