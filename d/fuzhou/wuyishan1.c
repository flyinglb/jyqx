// Room: /d/fuzhou/wuyishan1.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����ɽ��Բ������ʮ�����Ϫ����Ⱥɽ֮�У���Ϫɭ����
ʮ���壬��ˮ��ɽ��������������ƺ���ɽ��ˮ�㣬�ųơ���
��ˮ�������塱��
LONG );
	set("exits", ([
		"east"  : __DIR__"fzroad2",
		"west"  : __DIR__"wuyishan2",
	]));
        set("objects", ([
	]));
	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

