// Room: /d/fuzhou/pingshan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "������ɽ");
	set("long", @LONG
��ɽ�ų�Խ��ɽ����ب���ݳǱ���ɽ�»����£�������
������ɽ�ϸ���ųǣ������续��
LONG );
	set("exits", ([
                "southdown" : __DIR__"beidajie",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

