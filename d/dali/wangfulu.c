//Room: /d/dali/wangfulu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����·");
	set("long",@LONG
��������ǰ��������������ࡣ����������ڴ�Ĳ�ɫʯ������
���ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ�ӣ�ϰ�׸��죬��ʳ��
���޲�������ԭ��̫ѧ���ǵ�����֮��͸�ҿ��š�������һ�����Ƹ�
Ժ�������ϡ�����������������촣����ǰ��
LONG);
	set("objects", ([
	   CLASS_D("dali")+"/fusigui": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"   : __DIR__"paifang",
	    "north"  : __DIR__"wangfugate",
	]));
	setup();
	replace_program(ROOM);
}

