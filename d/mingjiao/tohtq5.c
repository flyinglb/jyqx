//TOHTQ5.C

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ɽ�����ƺ���ɲ⣬�����ϵ��ż�յ�������յö���һ�ɹ�
����������Ȼ�е�ʮ�ֳ�ʪ���ɶ��ڸ����ʵ������ƽ����
LONG );
	set("exits", ([
		"east"  :__DIR__"tohtq6",
		"south" :__DIR__"tohtq4",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
