
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ģ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡�������������һ�������
LONG );
	set("exits", ([
		"northeast" : "/d/guanwai/laolongtou",
		"northwest" : __DIR__"road2",
		"south"     : __DIR__"road4",
	]));
	set("objects",([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}



