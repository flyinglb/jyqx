// Room: /d/suzhou/zhenquting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��Ȥͤ");
	set("long", @LONG
ͤ�ڸ߸�����������д�ġ���Ȥ����һ�顣ͤ��װ�ξ���
��̻Ի͡����ܡ�Χ����ȹ���ϵ�̵��������ͼ��Ω��Ω
Ф���ڴ˿��Ի���ȫ԰��ɫ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"wenmeige",
		"northwest" : __DIR__"yanyutang",
	]));
	setup();
	replace_program(ROOM);
}

