//Room: /d/dali/chahua4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨԰");
	set("long",@LONG
����軨�ھ����£����������Ĳ軨��Ȼ���Ƿ�Ʒ����վ�ڲ軨
԰�У�������һƬ�������ٵĺ��档�����������£��м���軨����
�����ˣ�����԰�����Ĳ軨Χ�У��Խ�Ȼ��Ⱥ��
LONG);
	set("objects", ([
	   __DIR__"obj/chahua4": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"chahua5",
	    "northwest"  : __DIR__"chahua2",
	]));
	setup();
	replace_program(ROOM);
}

