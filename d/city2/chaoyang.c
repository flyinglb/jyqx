inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǳ����ţ���ǽ�Ͽ��š������š��������֡����ž��ڶ�
�ϱߣ����������������ǽ������ǵ�Ҫ�����̲�ʮ�����ܡ�һ������
�Ĵ���������죬ͨ����������������֡�������Ҳ���Գ������ǣ�
�����߾��ǽ��⣬������һ��Ƭ���֣�һ����Ҳ��������
LONG );
        set("outdoors", "city2");
	set("exits", ([
		"southeast" : __DIR__"chaoyan2",
		"northeast" : __DIR__"zhulin1",
		"west" : __DIR__"chaoyan1",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


