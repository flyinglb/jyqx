// Room: /d/shaolin/gulou4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��¥�Ĳ�");
	set("long", @LONG
������¥�ݴ��ֻ����һ�����£�ǽ��Ҳ�Ա���Щ������
Խ���������ϱߵ����䳡���޺��ã�������������Ŀ������ɮ
�����㼯�����䳡��ϰ�䣬ߺ����һ���󴫽����ġ����ߵĲ�
��¥������¥Ҳ��¶ȫò��
LONG );
	set("exits", ([
		"up" : __DIR__"gulou5",
		"down" : __DIR__"gulou3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

