// shidong.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ���Ƚϴ��Բ��ʯ������������ߵĴ���͸�˹�����ϸ���Ǵ���
ʱ�򣬷���ԭ��������ʯ���ϵ�һ���ˮ��͸��ˮ�����⿴ȥ��ֻ����Ϻˮ
�������ζ���ԭ���㾹����ˮ��֮�У�
LONG );
	set("exits", ([
		"south" : __DIR__"damen",
		"north" : __DIR__"shishi3",
		"east" : __DIR__"shiji2",
		"west" : __DIR__"shiji1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
