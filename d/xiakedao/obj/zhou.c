// zhou.c
#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");
}

void create()
{
        set_name("������", ({ "zhou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ĳ�Ʒ�����ࡣ\n");
                set("value", 20000);
        }
        setup();
}

int do_eat(string arg)
{
        int force_limit, neili_limit ;

        object me = this_player();

        force_limit = me->query_skill("force",1)*30;
        neili_limit = me->query("max_neili");

        if (!id(arg)||(arg!="gao"&&arg!="zhou"))
        return notify_fail("��Ҫ��ʲô��\n");

        if ( neili_limit <= force_limit  )
        {
             me->add("max_neili",random(50));
             me->add("neili",25-random(50));

message_vision(HIY "$N����һ�������࣬��Ȼ��ֻ��һ������ֱ���ķ�...\n" NOR, this_player());
        }
        else
message_vision(HIY "$N����һ�������࣬���Ǻ���ûʲô��...\n" NOR,this_player());

        destruct(this_object());
        return 1;
}

