#include <ansi.h>

inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW"��Ŀ��"NOR, ({"mingmu dan", "dan","mingmu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������Ŀ����\n");
                set("value", 200);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        
        if (!id(arg)||(arg!="dan"&&arg!="mingmu dan"))
	        return 0;
        if (me->query("age") >= 15)
        return notify_fail("�㳤���ˣ���Ŀ�����㲻�������ˡ�\n");
        if (me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        if(me->query_condition("mingmu_drug")>0) {
                me->receive_damage("jing",10);
                me->receive_damage("qi",20);
                me->receive_wound("jing",10);
                me->receive_wound("qi",20);
                message_vision(HIB "$N����һ����Ŀ������Ȼ��ֻ��һ�ɺ���ֱ��ٻ�... ԭ���Ƿ�ҩ�����ʵ��䷴��\n" NOR, this_player());
        } else {
                me->add("eff_jing",10);
                me->add("max_jing",10);
                me->apply_condition("mingmu_drug", 120);
                message_vision(HIW "$N����һ����Ŀ������Ȼ��ֻ��һ������֮����˫Ŀ͸��...\n" NOR, this_player());
        }
	this_object()->move(VOID_OB);
        destruct(this_object());
	me->start_busy(2);
        return 1;
}

