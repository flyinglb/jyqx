//Room: /d/dali/yanchi1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�سص̰�");
	set("long",@LONG
�����ǵ���ο;ۼ�֮������۷���������ʱʱ������ʤ����ˮ
翰��ĵ�أ����͡���ɲ�ڵᲨ�����֡�������������ͣ�۹ٶɣ���
�Ƹ�ʫ������֮Ϊ��ͣ���̻ᡱ������Ķ��ֲʺ硢��ɽ���ꡢ����
��𸡢��ϼ���졢�鷫ԶӰ���޲��������������ܡ�
LONG);
	set("objects", ([
	   __DIR__"npc/guigongzi": 1,
	   __DIR__"npc/enu": 2,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"yanchi2",
	    "southeast" : __DIR__"luojiadian",
	]));
	setup();
	replace_program(ROOM);
}

