//Room: /d/dali/langan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�����в�");
	set("long",@LONG
�����Ǹ������в㣬��¥��һ�������Ǽ�������گ���Ĵ���ŷ�
�Լ��������е��������Ҽһ������������谸����в�����෿��
��Ϊ������
LONG);
	set("objects", ([
	   __DIR__"npc/kid": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"      : __DIR__"langan1",
	]));
	setup();
	replace_program(ROOM);
}

