// Room: /d/shaolin/gulou3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
���������ƺ�Խ��Խխ��¥��Ҳ��Ϊ���ơ������ϲ�����
������������ľ����ɫҲ���¾ɲ�ͬ���Ӵ�����������������
�Կ��������еĲؾ�¥�ͷ���¥¶������һ�ǣ��������Ǻ��
���ݶ����ݼ������˸����ġ����֡�
LONG );
	set("exits", ([
		"up" : __DIR__"gulou4",
		"down" : __DIR__"gulou2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

