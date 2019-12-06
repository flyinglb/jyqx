string look_shelf();
#define WIZ_TOC "/u/atu/txt/toc"
#define WIZ_DIR "/u/atu/txt/"

inherit ROOM;
#include <ansi.h>

void create()
{	
set("short", "�����Ĺ�����");
set("long", @LONG	
�����ǰ����Ĺ����ҡ���ܰ�������ڷ�����Ʈ���ţ�һ̨����300A�������˵ع�����
ǽ���ϵ����(shelf)�������飬�Ա߹���һ������(duilian).
LONG	);	

	set("valid_startroom",1);
	set("no_steal", "1");
	set("exits", ([
		"down" : "/d/city/guangchang",
		"east" : __DIR__"neishi",
	]));
	set("item_desc", ([
		"duilian" : HIG "\n˭֪���в�\n" NOR + HIC "����������\n" NOR,
	       "shelf" : (: look_shelf :),
	]));
	setup();
}



void init()
{
        add_action("do_read", "read");
}

string look_shelf()
{
        this_player()->start_more(read_file(WIZ_TOC));
        return "\n";
}

int do_read(string arg)
{
        object me=this_player();
        if (arg == "" || file_size(WIZ_DIR + arg+".txt") <= 0)
                return notify_fail("����û���Ȿ�顣\n");

        me->start_more(read_file(WIZ_DIR + arg+".txt"));
        return 1;
}
