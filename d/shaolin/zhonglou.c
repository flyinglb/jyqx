// Room: /d/shaolin/zhonglou.c
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
		"west" : __DIR__"guangchang2",
		"enter" : __DIR__"zhonglou1",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

