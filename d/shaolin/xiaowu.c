// Room: /d/shaolin/xiaowu.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
�����м����һ�Ŵ���ϯ������ߵ��ǰ��������Է�������
���˼�ľ�Ƶķĳ��������Ѿ������˻ҳ��������Ǻþ�û�����ˡ�
�����ϵĳ��������м���ɢ�ҵ��㼣��ͨ��ϯ����Է���
LONG );
	set("exits", ([
		"south" : __DIR__"houshan",
		"north" : __DIR__"woshi",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

