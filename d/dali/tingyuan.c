//Room: /d/dali/tingyuan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ͥԺ");
	set("long",@LONG
����������������ͥԺ���м�һ��Сˮ̶������������಻֪��
�Ļ�����ֻϲȵ�ڻ����б�����ȥ�����Ա���ƬС���֣���Ӱ�·���
ʯ��ʯ�ʣ����������������塣
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"shijing",
	    "east"  : __DIR__"chahua1",
	    "north" : __DIR__"changlang",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
