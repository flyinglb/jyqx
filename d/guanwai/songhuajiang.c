// /guanwai/songhuajiang.c

inherit ROOM;

void create()
{
	set("short", "�ɻ�����");
	set("long", @LONG
�������ɻ����Ľ��棬�������ѽⶳ���峺�Ľ�ˮ���α�ȥ����������
��������֧���������������е��ڴ�β���Ŷ档
LONG );
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
