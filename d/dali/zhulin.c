//Room: /d/dali/zhulin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����С·");
	set("long",@LONG
һ��С·�����ֶ��������Ϸ��������һ��Ƭ̨���˾۾ӵĴ�
�򣬶�����ңң����ϲ�ݳǵĳ�ǽ����·��������ï�ܣ�ʱ��̨����
��������
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "southwest"  : __DIR__"wuding",
	    "northeast"  : __DIR__"xizhou",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

