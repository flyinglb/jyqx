// Room: /d/xiangyang/xinluofang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���޷�");
	set("long", @LONG
���޷�������˼���Ǹ�������ס�ĵط���������ʵ������
���Ѿ������������������Ӧ�ý����������ġ����Ǵ���Ѿ�
ϰ���ˣ����Ǳ㻹��ô�С�����ס�����������ˣ�Ҳ��Щ��
����ʹ����������·����������Ҳס���������ĸ�������
���кܶ�ܺõĻ����Ҷ�ϲ��������������ͷǳ�����
���ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"northroad1",
	]));
	set("objects", ([
		__DIR__"npc/gaoli" : 1,
	]));
	setup();
	replace_program(ROOM);
}

