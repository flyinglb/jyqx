// Room: /d/huashan/jzroad4.c

inherit ROOM;
void create()
{
	set("short", "����ɽɭ��");
	set("long", @LONG
����������ɽ·�ϡ�·����С����Χï��ɭ�����������Ұ��
ҹ�ݵ�˻������������ë���Ȼ��
LONG );
	set("exits", ([
		"westdown" : __DIR__"jzroad3",
		"southup"  : __DIR__"jzroad5",
	]));
	set("outdoors", "huashan");
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

