// bigbox.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("������", ({"big box", "box"}));
	set("long",
"����Ӹ�Լһ�ߣ�Ȼ��������ƮƮ�أ��ƺ����ﲢû������ô
�������򿪺иǣ��Ǻ��Ӿ�ǳ�ó��棬��׽�ֻһ�磬һֻ��
���ߵĺ��ӣ����غ���ȴ���ǳ���ϵñ��мв㡣\n");
	set("unit", "ֻ");
        set("no_sell", 1);
	set("open_count", 1);
	set("weight", 2000);
}

void init()
{
        add_action("do_open","open");
}

int do_open()
{
	if (query("open_count") > 0)
	{
		add("open_count", -1);
	        message_vision(HIR "$N���ִ����У�ֻ����ǰ��Ӱ����ԭ�������Ƕ�����\n" NOR, this_player());
        	this_player()->die();
	}
	else return notify_fail("�����类���˴��ˡ�\n");
        return 1;
}
