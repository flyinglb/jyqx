// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "��ĸ��");
	set("long", @LONG
����һ��ɽ·������һ�㶼����������Ϊ��Ϣ������ĵ�����
����̩ɽ�ڽ�������ɽΪ�ߣ��������������߱���ʯ������
LONG );
	set("exits", ([
		"eastup" : __DIR__"shijin",
		"southdown" : __DIR__"yitian",
	]));
	set("objects",([
		__DIR__"npc/jian-ke" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

