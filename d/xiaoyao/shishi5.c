// shishi5.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
�����ǵ���ʯ�ҵ�������һ���ˣ������Ǻں�����˵����������ֲ���
������ŵ�ǿ�ҵĸ��õĶ�������������ζ���������ǿ���뿪�ȽϺá�
LONG );
	set("exits", ([
		"up" : __DIR__"shishi4",
	]));
	set("objects",([
		__DIR__"npc/xiaoyaozi" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
