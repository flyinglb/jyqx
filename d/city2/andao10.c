
inherit ROOM;

void create()
{
	set("short", "��ػᰵ��");
	set("long", @LONG
�����߳��˰������㳤��������һ��������������ػ���ľ��
�Ĵ����������ĵƹ����˸е��ޱ���ů��
LONG );
	set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"andao9",
		"west" : __DIR__"andao9",
		"east" : __DIR__"andao9",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

