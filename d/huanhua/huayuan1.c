// huayuan1.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
���������е���ǰһ�����벻�����ﾹ����ôһ�����ڣ����ֻ��侹�࿪
�ţ�һ�ɴ��ⰻȻ�ľ������ڻ���֮�У���е������ˡ�
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"liangong2",
		"east" : __DIR__"liangong1",
		"west" : __DIR__"dating",
		"north" : __DIR__"liangong3",
]));
	setup();
	replace_program(ROOM);
}
