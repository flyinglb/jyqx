//Room: /d/dali/chahua9.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨԰");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨
԰����ߴ�����ͷ��ȥ����԰��ɫ������Ŀ�¡�����̨ͤ¥�󣬴���
���ȡ�
LONG);
	set("objects", ([
	   __DIR__"obj/chahua7": 1,
	   __DIR__"npc/muwanqing": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "southdown"  : __DIR__"chahua7",
	]));
	setup();
	replace_program(ROOM);
}

