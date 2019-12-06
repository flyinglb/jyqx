// jushi.c

inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", "����");
	set("long", @LONG
�����������˵����ң��������ڽ������˳ơ���Ů������Ϊ�˼��й�
�������ľ���ȴ�൱���أ�����֮�⣬����(window)���и���ױ̨(tai)��
ǽ�Ϲ���һ�ڱ���(sword)�� ��Ƥ�̿ڿ������Ƿ�����
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"changlang",
        ]));
        set("objects", ([
            CLASS_D("huashan") + "/yue-wife" :1,
        ]));
        set("item_desc", ([
		"window" : "�����������Ͽ�ˡ�������ȥ�������������Ŀѣ��\n",
		"sword"  : "�����ϴ�ǰ������ʱ���ص���Ȫ����\n",
		"tai"    : "����һ�ź�����ױ̨���뿪�ĳ���б���ż����ʻ���\n"
        ]));
//        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_move", "push");
        add_action("do_move", "move");
        add_action("do_pick", "pick");
        add_action("do_pick", "zhai");
}

int do_move(string arg)
{
	object paper, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="tai" )
	{
		if ((me->query("family/master_id") !="yue wife") &&
			objectp(present("yue wife", environment(me))))
		{
			return notify_fail(
"�����˺ȵ�����λ" + RANK_D->query_respect(me) + "���㲻����㷭�˼Ҷ�����\n");
			return 1;
		}
		if (!query("had_yunu"))
		{
			message_vision(
"$N������������룬����������һ����...��\n", this_player());
			paper = new("/clone/book/yunu_book");
			paper->move(__FILE__);
message("channel:rumor", HIM"��"+HIR+"ҥ��"+HIM+"��"+HIR+"ĳ�ˣ�"+this_player()->query("name")+"�õ���Ů��������\n"NOR, users());
			set("had_yunu", 1);
			return 1;
		}
		message_vision(
"$N������������룬��������ɶ��û��...��\n", this_player());
		return 1;
	}
	return 0;
}

int do_pick(string arg)
{
	object sword, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="sword" )
	{
		if ((me->query("family/master_id") !="yue wife") &&
			objectp(present("yue wife", environment(me))))
		{
			return notify_fail(
"�����˺ȵ�����λ" + RANK_D->query_respect(me) + "���㲻����㷭�˼Ҷ�����\n");
			return 1;
		}
		if (!query("had_sword"))
		{
			message_vision(
"$N�����ժ�±������������濪��...��\n", this_player());
			sword = new(__DIR__"obj/longquan");
			sword->move(me);
message("channel:rumor", HIM"��"+HIR+"ҥ��"+HIM+"��"+HIR+"ĳ�ˣ�"+this_player()->query("name")+"����һ����Ȫ������\n"NOR, users());
			set("had_sword", 1);
			return 1;
		}
		message_vision(
"$N����ȥժ�������ŷ���ֻʣ�����ˣ�������ͱ�����ȡ����...��\n", this_player());
		return 1;
	}
	return 0;
}
