//Room: /d/dali/dahejiewest.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��ͽ�");
	set("long",@LONG
����һ����ʯ��·���������˲��ٰ������Ե�ׯ�����¡�������
����ǵ��ؾ�פ�أ���������������ʿ�ǲ����ĺ�������������˾
�����ǵ����̫������һ�����Ϯ���š�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"   : __DIR__"shizilukou",
	    "north"  : __DIR__"tusifu",
	    "south"  : __DIR__"bingying",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

