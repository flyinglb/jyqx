// Room: /city2/chaguan.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ��
���Ű�����һ���ſ��������˿��ˣ������̸Ц����ͷ�Ӷ���
��Ҫ����������ƹʺ�ҥ�ԣ������Ǹ������ڡ�
LONG );
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"nandaj2",
	]));
	set("objects", ([
		__DIR__"npc/guanfuzi" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
