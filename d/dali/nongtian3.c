//Room: /d/dali/nongtian3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ũ��");
	set("long",@LONG
�����Ѿ���ƽԭ�ľ�ͷ����������վ���ɽ���ˣ�һЩ��ũ���
��٤������ķ������ǵطֲ���ɽ���£�һЩ�������������������
����·���ϵ�ɽ�����Ѷ�ȥ��
LONG);
	set("objects", ([
	   __DIR__"npc/nongfu2": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"nongtian2",
	    "southeast" : __DIR__"shanlu7",
	]));
	setup();
	replace_program(ROOM);
}

