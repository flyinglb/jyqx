//RJQMENLOU1.C

inherit ROOM;

void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
������һ���ʯ�ң�ʯ����������������ű����ܣ�ʮ��
�����������ȫ����������������Ѳ�ߣ��������ػ������ġ�
������һ��ʯ��ֱͨ¥�ϡ�
LONG );
	set("exits", ([
		"up" : __DIR__"rjqmenlou2",
		"east" : __DIR__"rjqyuan",
	]));
	set("no_clean_up", 0);
//	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
