//Room: /d/dali/gelucheng.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��³��");
	set("long",@LONG
�˳����������������θ����������³�����ݡ��²�������Ĵ�
������ɽ�ش��֣����������Ϊ�����ӹ��ڵ͵�Ҳ���Ƥ���ʺϷ���
ţ�򡣴�ȥ������������ɽ������ƽԭ�����д���
LONG);
	set("objects", ([
	   __DIR__"npc/shanyang": 2,
	   __DIR__"npc/muyangren": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northup"    : __DIR__"shanlin",
	    "south"      : __DIR__"zhenxiong",
	    "east"       : __DIR__"minadian",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

