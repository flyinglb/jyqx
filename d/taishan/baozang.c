// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������̩ɽ��һ����ʤ��������һ��״��ʨ�ӵľ�ʯ����Ϊʨ
���¡�������Ļ���Ҫ���ڶ�����Ķ�����Ҳ���������ǹŴ�
�����ĵط���������һ�������ڵļ�̩ɽ����
LONG );
	set("exits", ([
		"westup" : __DIR__"bixia",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

