//Room: /d/dali/shanlu6.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɽ·");
	set("long",@LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ��������һ
���޼ʵ���˫���ɴ�ɭ�֣���˵��а�̽��������л����·���Լ��
�ɼ�һЩ����Ĵ���ɽ·ת�������š�
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : __DIR__"shanlu5",
	    "east"       : __DIR__"gudao",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

