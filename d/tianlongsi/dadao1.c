inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��������ͨ��������ǡ�������
LONG );
        set("outdoors", "tianlongsi");
	set("exits", ([
		"northeast": "/d/emei/qsjie2",
		"south" : __DIR__"dadao2",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

