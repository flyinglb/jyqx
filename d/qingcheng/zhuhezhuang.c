// Room: /qingcheng/zhuhezhuang.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "פ��ׯ");
	set("long", @LONG
פ��ׯ�ഫΪ������Ϣ����֮�������г�Ⱥ��������Ϣ������
���ּ䡣
LONG );
	set("exits", ([
		"south"    : __DIR__"tianran",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

