
inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
��������������ֵľ�ͷ��������һ�������ûʵĴ�¥���Ŷ�
������һ�����ң�д�š������������ĸ����֣����ǿ����ʵ��ױʡ�
����ͨ���ذ��š�
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"di_an1",
		"south" : __DIR__"wangfu2",
		"north" : __DIR__"kang1",
	]));
	setup();
	replace_program(ROOM);
}

