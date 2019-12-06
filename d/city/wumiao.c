// Room: /d/city/wumiao.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������������������������Ϸ������������顰���Һ�ɽ����
���ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ�
�Ͼ���������ݡ��Ա��ƺ���һ�����š�
LONG
	);
	set("no_sleep_room", 1);
	set("item_desc", ([ /* sizeof() == 1 */
	  "northwest" : (: look_door,     "northwest" :),
]));
	set("no_steal", 1);
	set("no_fight", 1);
	set("exits", ([ /* sizeof() == 3 */
         "up" : __DIR__"ren",
	  "northwest" : "/d/wizard/guest_room",
	  "east" : __DIR__"beidajie2",
	]));
	
	set("objects", ([ /* sizeof() == 1 */
	  __DIR__"obj/box" : 1,
	]));
      	
	create_door("northwest","����","southeast",DOOR_CLOSED);
	set("no_clean_up", 0);
	set("valid_startroom", 1);

	setup();
}
void init()
{
//      object me;
//      me=this_player();
//      me->set("startroom",base_name(environment(me)));
        add_action("do_dazuo", "dazuo");
        add_action("do_tuna", "tuna");
        add_action("do_sleep", "sleep");
        return;
}

int do_dazuo(string arg)
{
        write("���������޷�����������\n");
        return 1;
}
int do_tuna(string arg)
{
        write("���������޷�����������\n");
        return 1;
}
int do_sleep(string arg)
{
        write("����������ôҲ˯���š�\n");
        return 1;
}
