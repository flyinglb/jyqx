// Room: /d/hengshan/cuipinggu2.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ͽ�����ʯ�ڶ�ֱ�����±�����һ�����������������
���յĺ�ɽɽ���У�ȴ����ʮ���������ڴ���ɽ������������Σ�ң�
������ȣ��������£���������¥�Կ���ȽȽ���䡣�Ǿ���������
�ˡ�
LONG
	);
	set("exits", ([
		"up"         : __DIR__"cuiping1",
		"northwest"  : __DIR__"cuipinggu1",
	]));

	set("outdoors", "hengshan");
        set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}

