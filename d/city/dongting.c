// Room: /city/dongting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ŷ�������֪���д����˵����ڡ����а���һ��ɼľԲ���ͼ���
���ӣ�������һ�׾��µ����˴�����ǽ�Ϲ���һ�����ã��������ͻ���ɽ����
��֪�����ֱʡ�
LONG );
	set("exits", ([
		"west" : __DIR__"ymzhengting",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

