inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG"����"HIY"��"NOR, ({"age dan","dan"}));
	set_weight(3000);
	set("unit", "��");
	set("long", "������ɽͯ��Ϊ���ഺ�����������ҩ�ľ��¶��ɵĵ�ҩ��\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();

	if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="dan")
	{
                if ((int)me->query("mud_age")>=2246400) 
                {
			write(HIW"�������һ��"HIG"����"HIY"��"HIW"�����ú���������һЩ��\n"NOR);
			me->add("mud_age",-86400);
			me->add("age",-1);
			destruct(this_object());
			me->unconcious();
		}
		else {
			write(HIG"����"HIY"��"RED"�������Ƶò����ر���ʣ������ȥû��ʲô���á�\n"NOR);
			destruct(this_object());
		}
	}
	return 1;
}
