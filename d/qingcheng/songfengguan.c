// Room: /qingcheng/songfengguan.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ɷ��");
	set("long", @LONG
�������ɷ�ۣ������������������������У������˲ű�
��֮�ʡ�������������׺�����������ò������ΰ�С��ȴ����
��һ����ʦ�����г����ݻ����Լ�����ɲ������ơ�
LONG );
	set("exits", ([
		"north" : __DIR__"shangqing",
	]));
	set("objects", ([
		__DIR__"npc/hai" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	"/clone/board/qingcheng_b"->foo();
        replace_program(ROOM);
}

