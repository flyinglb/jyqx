// Room: /d/shaolin/woshi.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�Է���ֻ��һ�����Ƶİ����������˰����õ���ϯ��ϯ���ϵ�
һ�����������ϡ�ϯ�ȱ���һ�Ѷ��˵ĵ��������ϰ߰ߵ���ƺ���
�ö���ǰ���µ�Ѫ����
LONG );
	set("exits", ([
		"south" : __DIR__"xiaowu",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

