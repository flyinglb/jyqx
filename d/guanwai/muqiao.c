// /guanwai/muqiao.c

inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
����һ�����ʧ�޵���ľ�ţ��ɼ��������������ɡ�����ĺ�ˮ���Խ�
�ɼ�������ﱾ�Ǻ�ͼ�����ǵĻ��Ǻӣ����ѷ��������ˡ��Ӱ��������û�
���ѳɵĳ�ǽ���ܶദ����̮�����ɴ��򱱾��Ǻ�ͼ�������ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"nancheng",
		"south" : __DIR__"road8",
	]));
	set("objects", ([
		__DIR__"npc/yuzhenzi" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

