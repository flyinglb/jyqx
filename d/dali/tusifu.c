//Room: /d/dali/tusifu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��˾��");
	set("long",@LONG
��˾���ǵ��ش�����Ϯ��˾���ϵ����ţ�һ�����ϵ�שľ�����
��ͥ�Ӹ����£�ׯ�ϼ�ʵ����ǰ�ǿ���ʯ�ף��е����������ƣ���
�ݹ���̨��ռ��Լ�˰�Ķ���������������������������᷿��
LONG);
	set("objects", ([
	   __DIR__"npc/datusi": 1,
	   __DIR__"npc/shicong": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "enter"  : __DIR__"tusimentang",
	    "south"  : __DIR__"dahejiewest",
	]));
	setup();
	replace_program(ROOM);
}

