// Room: /d/xiangyang/juyilang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ˮ������");
	set("long", @LONG
��ʱһ����ֱ�����ȣ�������һ����ˮ����ˮӳ�ų�����
���������峺�����ܿ���һЩ����������ȥ���������һ����
��԰��Բ�ڶ����������һ���᷿��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"juyihuayuan",
		"north" : __DIR__"juyiyuan",
	]));
	setup();
	replace_program(ROOM);
}

