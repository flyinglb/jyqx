// Room: /d/suzhou/zhipoxuan.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "Ҿ��ָ����");
	set("long", @LONG
��������Ϊ԰���Ӵ����ͺ����ѵĵط�����ʱҲ��Ϊ��Ϸ
˵���дʫ����֮��������ȡ���䡰ǰҾ®ɽ��һ����塱��
�����ġ�Цָͥǰ�ء���ʫ�⡣���ڰ�������ɫ��ƾ��������
��Ŀʯ����ᾣ��Ű��֦���ƣ�������Դ��ʮ�˾���֮�ơ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest"  : __DIR__"shizilin",
	]));
	setup();
	replace_program(ROOM);
}

