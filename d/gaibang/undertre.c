// Room: /d/gaibang/undertre.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ϻ����ײ������ܹ��߻谵����Ӱ�λΣ��ƺ��м����ڰ��Ķ���
������ߣ�ͨ������˷���  һλ����ؤ�����ֵ��������еĵ��ϡ�����
�����㷢��ǽ���ϻ��ŷ��ֲڵ�·�߲�ͼ��map����
LONG );
	set("exits", ([
		"up"   : __DIR__"inhole",
		"down" : __DIR__"chuchang",
		"1"    : __DIR__"xcandao1",
		"2"    : __DIR__"zlandao1",
		"3"    : __DIR__"slandao1",
		"4"    : __DIR__"xxandao1",
		"5"    : __DIR__"wdandao1",
		"6"    : __DIR__"hsandao1",
		"7"    : __DIR__"bjandao1",
		"8"    : __DIR__"qzandao1",
		"9"    : __DIR__"xsandao1",
		"a"    : __DIR__"dlandao1",
		"b"    : __DIR__"fzandao1",
	]));
	set("item_desc",([ "map" : 
		"����һ��ͨ��С�塣\n" +
		"���ڶ���ͨ�����֡�\n" +
		"��������ͨ�����֡�\n" +
		"�����ģ�ͨ�����ޡ�\n" +
		"�����壺ͨ���䵱��\n" +
		"������: ͨ����ɽ��\n" +
		"�����ߣ�ͨ��������\n" +
		"���ڰˣ�ͨ�����ˡ�\n" +
		"���ھţ�ͨ��ѩɽ��\n" +
		"���ڣ���ͨ������\n" +
		"���ڣ£�ͨ�����ݡ�\n"
	]));
	set("objects",([
		CLASS_D("gaibang") + "/liang" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

