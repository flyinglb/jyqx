// Room: /d/shaolin/dzdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�زص�");
	set("long", @LONG
���ǵزص����ز����������ز����������䣬������Ȼ��
���ٹ�����䣬������ǰ������ü��ɷ�����ֶ�����������һ��֮
�£��پ��ľ���ս���ֲ̿��ѡ�
LONG );
	set("exits", ([
		"east" : __DIR__"guangchang5",
	]));
//	set("objects",([
//		__DIR__"npc/mu-ren" : 1
//	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

