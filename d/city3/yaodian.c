// Room: yaodian.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "������ҩ��");
	set("long", @LONG
������ҩ�����ܶ���ԭ�򲻵���ҩ�������ŵĸ�������һֱ����
�á�һ�߽����ҩ�꣬���ŵ�һ�ɹ�Ũ�Ҵ̱ǵ�ҩζ���������ҩ��
������������ܣ��Ϳ���ҩ���ﻹ��һЩ��������ֵ��۹⿴�㡣��
�ǵ�����Ĺ����ҵģ���Ȼ���Ǻ��ǵġ�
LONG );
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"southeast" : __DIR__"westroad3",
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
