// /u/beyond/mr/shufang.c
// this is made by beyond
// update 1997.6.20
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIW"�鷿"NOR);
         set ("long",@long
��������������鷿, �����书���������, ��������, �����ϱ���һ
������,����ȫ��һ���Ÿߴ����ܡ��ú�ѧϰ, �ؿɳ�Ϊһ�����֡��鷿��
������һ�����ȣ������Ǵ�����������һ���᷿��
long);
         set("exits",([
             "west" : __DIR__"dating",
"north" : __DIR__"zishu",
             "east" : __DIR__"cl5-0",
             "south" : __DIR__"xiangfang2",
]));
set("objects",([
__DIR__"npc/feng" : 1,
]));
setup();
}


void init()
{
        add_action("do_sit", "sit");
        add_action("do_zhuan", "zhuan");

}


int do_sit(string arg)
{
	object me;
	me=this_player();
	
	if (!arg) return 0;
	if (arg !="chair") return 0;
	if (arg=="chair"){
		write("�����������ϣ����������Եá��㿴�����΢΢��ҡ����һ�¡�\n");
	this_player()->set_temp("marks/��1", 1);
	return 1;
	}
}
int do_zhuan(string arg)
{
	object me;
	me=this_player();
	if (me->query_temp("marks/��1")){
		message("vision", me->name() + "����ת��һ����ܣ�ͻȻ������һת�������ǰ������һ���бڡ�\n",
                    environment(me), ({me}) );
            message("vision", me->name() + "ͻȻ��Ӱһ���������ˡ�\n",
                    environment(me), ({me}) );
	me->move(__DIR__"jiabi");
            message("vision", me->name() + "���������˹�����\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/��1");
	return 1;
	}
}

