//Room: /d/dali/shanlu8.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
��·��ɽ�������Ѽ������������ɽ��ͨ����ĵ��ݵش�����
��ɽ�ƽ�Ϊƽ����ɽ����ż�����̣�͸�����ֵķ�϶������ȥ����
Լ�ɼ�һ����ˮ��Щ�����̡�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "eastdown"  : __DIR__"yangzong",
	    "westdown"  : __DIR__"shanlu7",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

