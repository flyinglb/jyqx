
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡����߾��Ǵ�֮���ˡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"haigang",
//		"west"  : __DIR__"road1",
		"south" : "/d/shaolin/ruzhou",
		"north" : __DIR__"road9",
	]));
	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}



