//Room: /d/dali/yanchi2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�سص̰�");
	set("long",@LONG
��ط羰���ˣ��ص̰�����������к��У����ϱ��Ա�ˮ������̲���
�ݺ�֮�࣬�����ڵ�أ����ֻ����£���������ɽ֮�������к��У�ң��
����ɽɫ����ӳ�ز��䣬������ˮ��������̣���Ȼ��ʤ��
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "westdown" : __DIR__"yanchi1",
	    "east"     : __DIR__"yanchi3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

