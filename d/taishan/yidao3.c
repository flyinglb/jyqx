// Room: /d/shaolin/yidao4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·����
����������������֡�
LONG );
	set("exits", ([
		"south" : __DIR__"yidao2",
		"north" : __DIR__"taishanjiao",
	]));
	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

