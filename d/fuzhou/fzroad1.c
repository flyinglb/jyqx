// Room: /d/fuzhou/fzroad1.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ϼ��");
	set("long", @LONG
������������ˮ����ϼ�롣���������������дУ�������
��������β�ɡ���;��ɽ·ʮ�����У������Ŀ���Ҳ����������
����Խ��Խ���Ա�ʶ�ˡ�
LONG );
	set("exits", ([
		"northdown" : "/d/quanzhou/qzroad4",
		"south"     : __DIR__"erbapu",
	]));
        set("objects", ([
		"/d/wudang/npc/yetu" : 2,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

