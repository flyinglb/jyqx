// /guanwai/baiyun.c

inherit ROOM;

void create()
{
	set("short", "���Ʒ�");
	set("long", @LONG
���Ʒ������֮����¹����֮�ϣ�Ϊ����ɽ���塣ɽ��Բ���ߴ�����
�ض�������Ρ����磬��һ�ڱ���ֱ�����졣������ã����ʮ�����¶��
Ω���˷峣���������ƣ����ղ�ɢ�������С����չ������׹ˣ���ɽ���ɰ�
�Ʒ⡱��������ٴ˷壬����ƮƮ����֮�С�
LONG );
	set("exits", ([
		"north"      : __DIR__"luming",
		"eastdown"   : __DIR__"tianchi1",
		"southwest"  : __DIR__"yuzhu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
