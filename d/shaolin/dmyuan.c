// Room: /d/shaolin/dmyuan.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��ĦԺ");
	set("long", @LONG
����һ�����ӵĵ��á����׵�ǽ�Ϲ����˸����书ͼ�ף���
�ٰ����ü����ɮ����������ͼ�׻���֮ǰ���ƺ��ڿ��˼����
�ϱ�ɽǽ�Ǹ߼��ݶ��Ĵ���ܣ��߽�ϸ���������Ǹ��Ÿ��ɵ���
�����ţ������а��ż��Ű���ڭ�ͼ����ţ���λ��ɮ�����붨�С�
�����и�¥����¥��
LONG );
	set("exits", ([
		"southdown" : __DIR__"wuchang3",
		"northdown" : __DIR__"guangchang5",
		"up"        : __DIR__"dmyuan2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

