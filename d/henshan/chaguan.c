// Room: /d/henshan/chaguan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ��
�ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ�ԣ�
�����Ǹ������ڡ�
LONG );
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"hengyang",
	]));
	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
	]));
//        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

