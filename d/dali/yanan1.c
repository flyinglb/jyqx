//Room: /d/dali/yanan1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ذ�");
	set("long",@LONG
�����Ի�أ�ʵ�����Ǹ��ܴ�ĺ�������ɽ��ˮԴ�ڶ࣬Ҳ����
�˴�Ƭ��ũ���ˮ�峺��ˬ�������٤���ĸ�Ů�ڴ�ϴ����ˮ����
�Ĳ�������ҵΪ��������������Ȼ����С��ͷ��ʱ�����δ�ͣ����Ҳ
������������ˮ���㡣������������������С·���ŵ���ϰ���ȥ��
LONG);
	set("objects", ([
	   __DIR__"npc/cunfu": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northeast" : __DIR__"luojiadian",
	    "west"      : __DIR__"yanan2",
	]));
	setup();
	replace_program(ROOM);
}

