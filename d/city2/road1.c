
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�
���̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·������
��������������֡����߾��Ǿ��Ƕ��š���������һ��С·��
LONG );

	set("exits", ([
//		"east"      : __DIR__"road10",
//                "east"      : "/u/gege/quest/work",
		"west"      : __DIR__"dongmen",
                "south"     : "/d/wudang/work2",
                "north"     : "/d/wudang/work3",
		"southeast" : __DIR__"road2",
		"northeast" : __DIR__"zhuang1",
	]));

	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));

 	set("outdoors", "city2");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}



