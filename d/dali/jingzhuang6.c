//Room: /d/dali/jingzhuang6.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
���������������е��з��񸡵�����������������ܣ���η�����
������죬����Э���������Ⱦ����������ɣ���������������������
�����ǵ���ʯ����������Ʒ���������ļҽ��ޡ������������˼�ƷҲ
����
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "up"    : __DIR__"jingzhuang7",
	    "down"  : __DIR__"jingzhuang5",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

