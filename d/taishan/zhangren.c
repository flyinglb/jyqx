// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "���˷�");
	set("long", @LONG
����λ����ʶ���������ĵط�����״����һ�����͵����ˡ�
�����лƻ�������·��ΪΣ�գ������ڽ�·��д�ϡ��س��ҡ���
�����������߱���᷶��ı����š�
LONG );
	set("exits", ([
		"east" : __DIR__"yuhuang",
		"northup" : __DIR__"beitian",
	]));
	set("objects",([
		__DIR__"npc/wei-shi1" : 2,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

