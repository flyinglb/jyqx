inherit ROOM;

void create()
{
	set("short", "������ͬ");
	set("long", @LONG
�ֵ���һ����Ҳ����������ͻȻ�е㺦�����������ϱ���һ�ҹײĵꡣ
���ϱ���һ���������С��㲻֪��Ҫ��Ҫ���������ߡ�������������
ȥ�ɣ���á����������������ĵ���һ��������ס�ض���˵��
LONG );
        set("outdoors", "city2");

	set("exits", ([
		"southeast" : __DIR__"guancai1",
		"north" : __DIR__"alley1",
		"southwest" : __DIR__"alley3",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

