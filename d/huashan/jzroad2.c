// Room: /d/huashan/jzroad2.c

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡��м�һ��С·�����߶��Ǻ�ɭɭ�ļ��ɸߵ���
����������ˣ����Կ������ߺøߵ�һ����ɽ��
LONG );
	set("exits", ([
		"west" : __DIR__"jzroad1",
		"east" : __DIR__"jzroad3",
	]));
	set("outdoors", "huashan");
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


