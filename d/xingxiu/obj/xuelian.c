// medicine: xuelian.c
// Jay 3/18/96
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("��ɽѩ��", ({"xuelian", "lian", "lotus"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "����һֻ֧���ں���ĵط�����������ѩ����\n");
                set("value", 100);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

// function of this medicine needed here
       if ((int)this_player()->query("eff_qi")==
           (int)this_player()->query("max_qi"))
                return notify_fail("�����ڲ��ó��ⱦ��!\n");
       this_player()->receive_curing("qi",200);
       message_vision("$NС�ĵس���һ��ѩ��,��ʱ����������ˬ�˲���!\n",
                      this_player());

       destruct(this_object());
       return 1;
}

