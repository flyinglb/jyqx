inherit ROOM;

void create()
{
	set("short", "�ذ��Ŷ����");
	set("long", @LONG
����һ����������Ĵ��������ͨ���ذ��š�����ͨ����������
�ϱ߾��Ƕ����ˣ�һ���˶��������Ƕ�ȥ��
LONG );
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"wangfu3",
		"west" : __DIR__"di_an2",
		"south" : __DIR__"dongchangdamen",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


