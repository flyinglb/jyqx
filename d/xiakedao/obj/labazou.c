// labazou.c ������

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
        set_name("������", ({"laba", "zhou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����࣬����������ð��أ����һ�������ݴ���
�׳彫������һ���ྡ������֮ɫ������ȥ˵�����Ĺ��졣����ҩ���̱ǣ��䶾��֪��\n");
                set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{
//        int force_limit, neili_limit, force_skill, add_skill, improve;

        object me = this_player();

        //force_limit = me->query_skill("force")*10;
        //neili_limit = me->query("max_neili");
        //force_skill = me->query_skill("force", 1);

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        if ( (int)me->query_temp("num" ) > 0 )
        {
                me->add_temp("num", 1);
                me->add("max_neili", -100);
                message_vision(HIR "$N�ֺ���һ�������ֻ࣬���øγ���ϣ���������
��ԭ���ȵ�̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        }

        else
        {
/*              if ( improve < 100 ) {
                        add_skill = force_skill + (100 - improve)/5 + 1;
                        me->set_skill("force", add_skill );
                }
*/
                me->add("max_neili", 100);
                me->add("neili", 100);

                message_vision(HIY "$N����һ�������࣬��Ȼ��ֻ��һ�ɺƵ��ޱȵ���
��ֱ�嶥��...\n" NOR, this_player());
                me->set_temp("num", 1);
        }

        me->unconcious();
        destruct(this_object());
        return 1;
}


