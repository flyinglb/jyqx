//TOHTQ3.C

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
ɽ·���������£�ǰ���ƺ�û��·�ˡ���ɽ�����ܼ���ѻ��Ⱥ
������������Ʈ������֪��֮��
LONG );
	set("exits", ([
		"southup" :__DIR__"tohtq2",
		"enter"   :__DIR__"tohtq4",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
