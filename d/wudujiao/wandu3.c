// by mayue

inherit ROOM;
#include <ansi.h>
string* npcs = ({
	__DIR__"npc/wandu1",
	__DIR__"npc/wandu2",
	__DIR__"npc/wandu3",
	__DIR__"npc/wandu4",
	__DIR__"npc/wandu5",
});

void create()
{
	set("short", "�򶾿�");
	set("long", @LONG
������ɽ���ڲ���֧���������Ѿ�û��һ˿�����ˣ��ڶ�����
ʲôҲ�������������ұ��Ϻ������ż��겻֪����С�ݡ����Դ���
һ�����С���������
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
//             "south" : __DIR__"wandu3",
//		"westdown" : __DIR__"wdsl3",
		"north" : __DIR__"wandu2",
	]));
        set("objects", ([
	        npcs[random(sizeof(npcs))] : 1,
	        npcs[random(sizeof(npcs))] : 1,
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
	if( (!arg) ||!((arg == "�ұ�") || (arg == "����")))
		return notify_fail("��Ҫ��ʲô��\n");
		message_vision(HIC"$N�����ұ���ͻ����ʯ����ѵ�������ȥ��\n\n"NOR,me);
        ob = load_object(__DIR__"dongxue");
        ob = find_object(__DIR__"dongxue");
        message("vision", me->query("name")+"����������������\n", ob);
        me->move(__DIR__"dongxue");
        return 1;
}