// Room: wuguanchen.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ţ��ݶ���");
	set("long", @LONG
�����ǡ���ţ��ݡ����ڶ�����ʦ�������������¼��ܣ�������
���������ڹ��������мܣ�����צ��������������
LONG );
	set("objects", ([
		__DIR__"npc/longquan" : 1,
	]));
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"wuguan",
	]));
	setup();
	replace_program(ROOM);
}
