// Room: wuguanchen.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ţ���һ��");
	set("long", @LONG
�����ǡ���ţ��ݡ�����һ����ʦ����䰽������¼��ܣ�������
���������ڹ��������мܣ�����ȭ���������ȷ�������������
LONG );
	set("objects", ([
		__DIR__"npc/chenhu" : 1,
	]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"wuguan",
	]));
	setup();
	replace_program(ROOM);
}
