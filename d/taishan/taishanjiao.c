// Room: /d/taishan/taishanjiao.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "̩ɽ����");
	set("long", @LONG
̩ɽ�ų��ɽ��Ϊ�����Ķ�����Ϊ���̵ڶ�С���죬���� "������
��" ֮�������� "̩ɽ������" �������ڡ������͵���ڷ��ˡ�
LONG );
	set("exits", ([
		"north" : __DIR__"daizong",
		"south" : __DIR__"yidao3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

