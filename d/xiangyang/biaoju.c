// Room: /d/xiangyang/biaoju.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����ھ�");
	set("long", @LONG
������һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ����
�ɶ�ߵ���ˣ���������Ʈ����������ý�������һͷ����
��צ��ʨ�ӣ�ʨ����ͷ��һֻ������衣����������д�š���
���ھ������ֺš��˸����֣������������վ��Ƿ����������
�������ʣ�������ͷ���Ű��ء�
LONG );
	set("exits", ([
		"west" : __DIR__"eastroad1",
	]));
	set("objects", ([
		__DIR__"npc/biaotou" : 2,
	]));
	setup();
	replace_program(ROOM);
}

