//Room: /d/dali/nianhuasi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�黨��");
	set("long",@LONG
ɽ·Խ��Խ��Ƨ��ת���ĸ�ɽ�꣬����һ��СС�Ĺ���ǰ������
��д�š��黨�¡����֡�����Ǵ�����̡����������⣬������ʮ��
С���԰ټƣ��������黨�¡��ش�ƫƧ��������𣬼������Ӵ���֮
�ˣ����Ҳ��֪����
LONG);
	set("objects", ([
	   __DIR__"npc/pochen": 1,
	   __DIR__"npc/poyi": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"      : __DIR__"nianhua1",
	    "southdown"  : __DIR__"shanlu2",
	]));
	setup();
	replace_program(ROOM);
}

