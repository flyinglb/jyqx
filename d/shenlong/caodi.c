#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", "�ݵ�");
    set("long", @LONG
������һƬ����Ĳݵأ��м�����������ˣ�����ܿ����˸�ɫ��
�ʻ���һ�����紵�������µĿ����д������Ƶ����Ļ��㡣
LONG );

	set("exits", ([
		"south" : __DIR__"kongdi",
		"north" : __DIR__"xiaowu",
	]));
	set("outdoors", "shenlong");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

