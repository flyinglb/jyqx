//Room: /d/dali/jianchuankou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ɽ��");
	set("long",@LONG
�����ǲ�ɽ��´��һ�����ĳ��򡣴˵�����ɽ�ڣ����߳�ɽ����
������������·���У�Ψ�д���������ɽ������Ǵ������������
����Ҫ�壬������ڴ����е�¥����������פ�����йٱ������վ��
Ѳ�ߣ��̲�������ˡ�
LONG);
	set("objects", ([
	   __DIR__"npc/jiang": 1,
	   __DIR__"npc/bing": 3,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"shanlu1",
	    "south"      : __DIR__"jianchuan",
	]));
	setup();
	replace_program(ROOM);
}

