// Room: /qingcheng/path1.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ɽ���");
	set("long", @LONG
��������ɽ����ϡ�ɽľ���գ��ľ����ˡ����ˡ���ǡ�ľ��
¥�����Ͼ�����Ȼͼ���ˡ����Ϸ����ǽ�������
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"southeast" : __DIR__"jianfugong",
		"westup"    : __DIR__"tianran",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

