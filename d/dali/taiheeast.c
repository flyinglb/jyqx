//Room: /d/dali/taiheeast.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","̫�Ͷ���");
	set("long",@LONG
̫�ͽ�������������ϱ��ţ���������ǳ�����Ҫ�ֵ�������
������ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ
�ӣ�ϰ�׸��죬��ʳ�����޲�������ԭ��������Ѧ�ϳ����̣�������
ҩ�̡�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"   : __DIR__"taihejiekou",
	    "east"   : __DIR__"stoneshop",
	    "north"  : __DIR__"garments",
	    "south"  : __DIR__"yaoshop",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

