// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "���ɷ�");
	set("long", @LONG
������ʮ���̵��м䣬���������˵�һ�γ�Ϊ��ʮ�ˣ�������
ֱ�������ŵ�һ�γ�Ϊ��ʮ�ˡ��ɴ˿���ʯ���ϣ�������˿��Կ�
��ǰ����˵�Ь�ף�ǰ����˻�ͷ��ɼ���������˵ķ���������
��һ����ÿ��ʮ������Ҫ��һ��Ϣ��
LONG );
	set("exits", ([
		"northup" : __DIR__"nantian",
		"southdown" : __DIR__"longmen",
	]));
	set("objects", ([
		__DIR__"npc/jianchu" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

