// Room: /d/xiangyang/jiangjuntang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
�����ǽ������Ĵ��ã������������һ�����͵Ľ�������
һ��ƣ����������ս�չ��ģ�����������߰��ű����ܣ�����
��������Ѫ����ӳ�żܺ��ս�죬����ҫ�ۡ����ཫ��������
��δϴ������־���������׳��
LONG );
	set("exits", ([
		"south" : __DIR__"jiangjunyuan",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
		__DIR__"npc/zuo" : 1,
		__DIR__"npc/pian" : 1,
		__DIR__"npc/ya" : 1,
		__DIR__"npc/pi" : 1,
	]));
	setup();
	replace_program(ROOM);
}

