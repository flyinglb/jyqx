// Room: sroad5.c

inherit ROOM;  
#include <ansi.h> 
int pick(string);

void create()
{
        set("short","ɽ·");
        set("long",@LONG
Խ�����ߣ�����������˪ѩ����׷׶��¡���ĿԶ����ֻ��
����ѩ�ף����ﾧӨ����Զ���ƺ��и�������ɽȪ�ٲ����������
��������������ʻ��������ޣ����㲻�ɵüӿ�Ų���·�Խ���
��һ����������ice�����������£�����������ʱ������������
֮ʱҲ������Ϊ����ʹ�á�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "southdown"  : __DIR__"sroad4",
            "north"  : __DIR__"sroad6",
        ]));
        set("item_desc", ([
            "ice" : "����һ����Ө��͸�ı�������������Ű�(pick)����������\n",
        ]) );
        set("no_clean_up", 0);
	set("ice_count", 5);
        setup();
} 

void init()
{
 add_action("do_pick","pick");
}

void reset_ice()
{
	set("ice_count", 5);
	delete("ice_call_out");
}
int do_pick(string arg)
{
	object me = this_player();

	if (arg == "ice") {
		if (query("ice_count")) {
			message_vision(HIW"$NС������ش�·�Ե����ϰ���һ������������\n"NOR, me);
			add("ice_count", -1);
			new(__DIR__"obj/ice")->move(me);
			return 1;
		}
		else {
			if (!query("ice_call_out")) {
				remove_call_out("reset_ice");
				set("ice_call_out", 1);
				call_out("reset_ice", 600);
			}
			return notify_fail("�����Ѿ��������ˡ�\n");
		}
	}
	return 0;
}