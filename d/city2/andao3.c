
inherit ROOM;

void create()
{
	set("short", "��ػᰵ��");
	set("long", @LONG
һ�߽�������ĵص�������������ϱߴ�������е���Щ
�䡣���߶�����ǽ����Լ������������ŵ���ص�������
LONG );
	set("exits", ([
		"north" : __DIR__"andao1",
		"south" : __DIR__"andao5",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

