//Room: /d/dali/wfdating.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������������");
	set("long",@LONG
���˴��������ۿ��Ǵ�����ֻ������һ�飬���ң�д�š������
ʯ���ĸ����֣��������š���î���ʡ��ĸ�С�֣����������������
����һʱҲ����������ࡣ�������������������˰칫֮������
�����ʷ���������һ��ʯ��ͨ����լ��
LONG);
	set("objects",([
	    __DIR__"npc/jiading": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"   : __DIR__"zhangfang",
	    "east"   : __DIR__"shijing",
	    "north"  : __DIR__"zonglichu",
	    "out"    : __DIR__"wangfugate",
	]));
	setup();
	replace_program(ROOM);
}

