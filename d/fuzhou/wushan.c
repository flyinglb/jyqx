// Room: /d/fuzhou/wushan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "������ɽ");
	set("long", @LONG
���ݹų���ɽ���Գ�����ɽ����ɽ����ɽ��ɽ����֮��
Ҳ����ɽ����������
LONG );
	set("exits", ([
                "northdown" : __DIR__"xidajie",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

