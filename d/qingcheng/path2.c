// Room: /qingcheng/path2.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "���ɽ·");
	set("long", @LONG
���������ɽ·�ϡ�ɽľ���գ��ľ����ˡ����Ͼ�����ʦ����
��������Ȼͼ����
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"westup"   : __DIR__"tianshidong",
		"eastdown" : __DIR__"tianran",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

