// Room: /d/fuzhou/fzroad7.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
���뽭�������ǲ�����ɽ���������Ĺȣ����ղ�����⡣����
ɽ�ж������޳�û�޳�����·������һ��������ŵ�һ���ȷ��˱�
������
LONG );
	set("exits", ([
		"northwest" : "/d/henshan/hsroad2",
		"eastup"    : __DIR__"fzroad6",
	]));
        set("objects", ([
		__DIR__"npc/huananhu" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}

