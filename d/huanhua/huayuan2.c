// huayuan2.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
��������㲻�������泩����԰�м���һ����ɽ�������Ȼ����������ˮ��
�����ɶ��칤��С·���Ը��ֻ��侹�࿪�ţ����涷�ޣ������⻨��֮�У���
�Ĳ���Ҳ���ˡ�
LONG
	);
        set("exits", ([ 
		"east" : __DIR__"dating", 
		"south" : __DIR__"liangong4",
		"west" : __DIR__"liangong5",
		"north" : __DIR__"liangong6",
]));
	setup();
	replace_program(ROOM);
}
