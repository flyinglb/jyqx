
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ����Ͼ��Ǳ����ǡ������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·�����������и�С
̯�������������ЪϢ��
LONG );
	set("exits", ([
		"north" : __DIR__"road4",
		"south" : __DIR__"road9",
		"west" : __DIR__"xiaotan"		
	]));
	set("outdoors", "city2");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}



