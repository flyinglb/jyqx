// Room: /d/fuzhou/dongdajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�ֵ����࣬��ľ���졣����ʢ�Ŀ��ȣ���ֲ����������
ˬ���������ųǡ��������ǿ͵꣬����ͨ��ɽ�ϡ�
LONG );
	set("exits", ([
		"southup" : __DIR__"yushan",
		"north"   : __DIR__"rongcheng",
		"east"    : __DIR__"dongxiaojie",
		"west"    : __DIR__"dongjiekou",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

