// Room: /d/shaolin/gulou1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
��������¥�ĵײ㣬һ���������ǽ�ϵĻ�ש��϶��͸��
����������ש����Ͷ�±��µĹ�Ӱ����ͬһ����������ơ���
�Ͽ���������ľ¥�����ƶ��ϣ��ƺ����޾�ͷ��ǽ�ǣ��ݼ���
�൱�ྻ������������ɮ�˴�ɨ��
LONG );
	set("exits", ([
		"up" : __DIR__"gulou2",
		"out" : __DIR__"gulou",
	]));
	set("objects",([
		__DIR__"npc/saodi-seng" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

