// Room: /d/henshan/hsroad3.c ����·
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡����治Զ
���Ǻ����س��ˡ�
LONG );
        set("outdoors", "henshan");

	set("exits", ([
		"northeast": __DIR__"hsroad2",
		"west"     : __DIR__"hengyang",
	]));

        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

