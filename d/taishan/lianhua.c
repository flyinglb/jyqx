// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ʵ��������ɽ���ܴض��ɣ�״������������Ϊ������
����Σ�����𣬽��廨�¡�����������󣬿ɿ������̵��е�����
��С�ϰ��������󣬹ʴ��������ֽ����˷塣�����߱����������
�嶥��
LONG );
	set("exits", ([
		"westup" : __DIR__"tianjie",
		"northup" : __DIR__"shixin",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

