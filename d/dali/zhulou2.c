//Room: /d/dali/zhulou2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��¥");
	set("long",@LONG
һ���׼��̨����¥������ǽ�ڽ������ӣ���������һ��������
����̨�����ڼ�������¯�����崫ͳϯ�ض�˯�����������޴�����ǽ
���е��죬�����ڳ���ʯ�Ѽ�̨����޼Ҿߡ�
LONG);
	set("objects", ([
	   __DIR__"npc/kid": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"   : __DIR__"zhulou1",
	]));
	setup();
	replace_program(ROOM);
}

