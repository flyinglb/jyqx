// Room: /d/shaolin/gulou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��¥СԺ");
	set("long", @LONG
����һ��שľ�ṹ�ı����������߲㣬�������˽��Σ�����
���ᣬ�ܽ��Ϲ�����һ����Сͭ�壬��綣�����졣����ǽ����
�յ�������������ǵ�����һ������̬άФ��������������֮
�֡�������ڴ�����һ�ȹ��ε�Сľ�ţ����������ò���Ϳ�棬
��������������ɽ�������ڷ𽲾�ʱ�����Ρ�
LONG );
	set("exits", ([
		"east" : __DIR__"guangchang2",
		"enter" : __DIR__"gulou1",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "enter" ) return 0;

	return ::valid_leave(me, dir);
}

