//Room: /d/dali/shanlu7.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
�н�����گ��᫵�ɽ���С���ɽ����������ï�ܷ�ʢ����ľ��
֦辺���������·�����������ѡ�����ɽ�񾭳����߲ſ��������ĵ�
·����������ˣ�������Ȼ��ҪЮ����������ʱ׼������·����ľ��
�����ϰ���
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northwest" : __DIR__"nongtian3",
	    "eastup"    : __DIR__"shanlu8",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

