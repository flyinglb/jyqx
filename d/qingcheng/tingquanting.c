// Room: /qingcheng/tingquanting.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��Ȫͤ");
	set("long", @LONG
��ʯ�����£����Ǻ���Ϫ��������Ϫ�ϵ���Ȫͤ���Ĺ�ɽ��ˮ
�ƣ�������������Ȫ������У��������Ღ�����������̣������
����
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"westup"   : __DIR__"sandaoshi",
	]));
	set("objects", ([
		__DIR__"npc/luo" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

