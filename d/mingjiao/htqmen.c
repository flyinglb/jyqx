//HTQMEN.C

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Ǻ�����Ķ��ţ��Ŷ�����������ĺ������ڣ����Ϲ�����
�£������̵���˭Ҳ�����㡣�ű�����̸���Ʊ߷����죬���ź�
�����֡�
LONG );
	set("exits", ([
		"enter" : __DIR__"htqdating",
		"south" : __DIR__"tohtq7",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
