//Room: /d/dali/paifang.c
//Date: June. 29 1998 by Java

inherit ROOM;

void create()
{
	set("short", "�Ʒ�");
	set("long", @LONG
���Ǵ���ǵ��Ʒ�������һ���Ʒ���д���ĸ���ɫ����: ʥ����
�ȡ������ǻʹ���������һ����ʯ��������ڴ�������������ӣ���
�ʹ�������ߣ������᲻�������������糱��
LONG );
        set("outdoors", "dali");
	set("exits", ([
		"east"  : __DIR__"wangfulu",
		"west"  : __DIR__"yujie",
		"south" : __DIR__"taihejiekou",
		"north" : __DIR__"northgate",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

