//Room: /d/dali/chahuashan5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨ɽ");
	set("long",@LONG
�����ڲ軨ɽ�ϣ�������������ïʢ�Ĳ軨����Ȼ����
���Ƿ�Ʒ����ż��Ҳ����һ�����Ʒ�������С�������Զ�Ǵ���
�ǵı��ţ��ϱ߲�Զ�ǳ�ǽ��
LONG);
	set("objects", ([
	   __DIR__"obj/shanchahua": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "eastdown" : __DIR__"chahuashan6",
	    "west"     : __DIR__"chahuashan2",
	]));
	setup();
	replace_program(ROOM);
}

