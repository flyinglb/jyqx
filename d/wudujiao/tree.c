// by mayue

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǵ����Ķ��ˣ�������Ũ�ܵ�֦Ҷ��ʪ������̦޺��һ��
΢�紵������Ҷ���������������������������ȥ����ֻ����һ��
���Σ����뻹�ǸϿ���ȥ�ɡ�
LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
//             "south" : __DIR__"wandu3",
//		"westdown" : __DIR__"wdsl3",
//		"north" : __DIR__"wandu2",
	]));
        set("objects", ([
                  __DIR__"obj/xiang": 1,
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
	if( (!arg) ||!((arg == "tree") || (arg == "down")))
		return notify_fail("��Ҫ��ʲô��\n");
		message_vision("$N����������֦�������������ȥ��\n\n",me);
        ob = load_object(__DIR__"nanyuan");
        ob = find_object(__DIR__"nanyuan");
        message("vision", me->query("name")+"��������������������\n", ob);
        me->move(__DIR__"nanyuan");
        return 1;
}