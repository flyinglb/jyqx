//Room: /d/dali/chahuashan6.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�軨ɽ��");
	set("long",@LONG
����ǲ軨ɽ�����棬��Ȼ�д����Ĳ軨ʢ���š�����Ȼ����ɽ�ϵ�
Ʒ�ֺ��ˣ����Ƿ�Ʒ��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "westup"     : __DIR__"chahuashan5",
	    "southeast"  : __DIR__"dadieshui",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

