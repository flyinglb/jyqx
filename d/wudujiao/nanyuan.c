// by mayue

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�������Ͽ�Ժ��Ժ�����пúܴ������������մ���ס��Ժ���ﾲ
���ĵģ�ֻ�м�ֻ�ߴ�Ĳ��������������ⲽ�� 
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"yaoshi",
		"south" : __DIR__"liandu",
		"west" : __DIR__"xiangfang",
		"north" : __DIR__"lianwu",
	]));
        set("objects", ([
                  __DIR__"npc/zangao": 2,
	]));
    

	setup();
//	replace_program(ROOM);
}

void init()
  {
       add_action("do_climb","climb");
  }
int do_climb(string arg)
{
       
	object me=this_player();
	object ob; 
	if( (!arg) ||!((arg == "tree") || (arg == "up")))
		return notify_fail("��Ҫ��ʲô��\n");
		message_vision("$P���˴��֣�����������֦��������¾�������ȥ��\n\n",me);
        ob = load_object(__DIR__"tree");
        ob = find_object(__DIR__"tree");
        message("vision", me->query("name")+"����������������\n", ob);
        me->move(__DIR__"tree");
        return 1;
}
