// Room: /qingcheng/shangqing.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "���幬");
	set("long", @LONG
���幬���Ͼ���������ǰɽ�ţ�������ͣ���Ϊ�鶯�����ڵ�
�ù�ɫ���ţ������̫���Ͼ���������������������ɽǰĦ��
ʯ�� "���µ�����ɽ" ���ƻ�񣬺���׳�ۡ�
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"westdown" : __DIR__"sanwanjiudao",
		"westup"   : __DIR__"huyingting",
		"west"     : __DIR__"yuanyangjing",
		"east"     : __DIR__"maguchi",
		"south"    : __DIR__"songfengguan",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

