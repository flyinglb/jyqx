// Room: /d/shaolin/yidao.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ�
���̣����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·����
����������������֡������Ǹոճ������������˵�������.
LONG );
	set("exits", ([
		"west" : "/d/city/dongmen",
                "east" : __DIR__"yidao1",
                "north" : "/d/players/xinshoumeng",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 3,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

