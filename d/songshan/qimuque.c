// Room: /d/songshan/qimuque.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "��ĸ��");
	set("long", @LONG
��ĸ������ɽ��´������£��Ǻ�����ĸ��ǰ������ڣ���̫��
��ͬΪ����������֮һ��
LONG );
	set("exits", ([
		"east"  : __DIR__"qimushi",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

