//Room: /d/dali/badidian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�͵ĵ�");
	set("long",@LONG
������Ǵ�������Ҫ��͵ĵ飬�����ĵ���Ҫ�θ���������Ĳ�
��ֲ��ڸ��������ڶ���ˮ�ȵ����У��͵ĵ����ܶ�ũ��Դ�Ϊ��
�ģ���·��ͨ�˴����Ӹ����Ĳ��䡣
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"zhenxiong",
	    "south"      : __DIR__"lushui",
	    "eastup"     : __DIR__"lushuieast",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

