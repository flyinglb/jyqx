// Room: /qingcheng/zushidian.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ʦ��");
	set("long", @LONG
��ʦ���������乬����ʦ�����ԯ�壬�������Ϫ��ʮ����
�ġ���������̨���ഫΪ�Ƶ��ܵ�����
LONG );
	set("exits", ([
		"eastup"    : __DIR__"chaoyangdong",
		"southdown" : __DIR__"gulongqiao",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

