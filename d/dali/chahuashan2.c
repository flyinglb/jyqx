//Room: /d/dali/chahuashan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨ɽ");
	set("long",@LONG
�����ڲ軨ɽ�ϣ�������������ïʢ�Ĳ軨����Ȼ����
���Ƿ�Ʒ����ż��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ���
�ǵ����ţ����߲�Զ�ǳ�ǽ��
LONG);
	set("objects", ([
	   __DIR__"obj/shanchahua": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"     : __DIR__"chahuashan3",
	    "south"     : __DIR__"chahuashan4",
	    "east"      : __DIR__"chahuashan5",
	    "westdown"  : __DIR__"chahuashan1",
	]));
	setup();
	replace_program(ROOM);
}

