// Room: /d/suzhou/canlangting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����ͤ�����ݵı�����ϲ࣬��Ϊ����������ţ�ʹ����
Ů���ٶ�ϲ����������ͥɢ������ͤ�з�����ȥ������һƬ��
�̵Ĳ�ƺ��ͤ����Ȼ���ʴ�֮�У���������������ƿƣ�����
�ܿ����ܣ�ͤ�ϵĶ��Һ�ʯ���ϵ����(lian)ʹ�˸���ϲ����
�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("item_desc", ([
		"lian" :
"������±��޼� ��ˮԶɽ������\n",
	]));
	set("exits", ([
		"southeast" : __DIR__"dongdajie1",
		"southwest" : __DIR__"xidajie1",
		"north"     : __DIR__"beidajie1",
		"south"     : __DIR__"baodaiqiao",
	]));
	setup();
	replace_program(ROOM);
}

