// Room: /d/henshan/hsroad4.c ����·
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡����治Զ
���Ǻ����س��ˡ�����������һ�������
LONG );
        set("outdoors", "henshan");

	set("exits", ([
		"east"  : __DIR__"hengyang1",
                "north"  : "/d/bupingshe/damen",
		"west"  : __DIR__"hsroad5",
	]));

        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

