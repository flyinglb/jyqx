// Room: tanggate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "���Ŵ���");
	set("long", @LONG
��������������µ����ŵĴ���(gate)�����Ž���ʮ��Ρ�룬��
ǽ�����µ�ͭ�����Ž����رգ��������ŵ���һ���ſ���������ƿ�
���ǲ��ý�ȥ�ˡ�
LONG
	);
        set("outdoors", "chengdu");
	set("no_fight",1);
	set("exits", ([
		"north"  : __DIR__"northroad2",
	]));
	set("objects", ([
		__DIR__"npc/tangdun" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
