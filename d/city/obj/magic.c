#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( HIR "���泤��" NOR, ({ "fireblade" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"һ�ѷǽ��ľ��ͨ�尵��ĳ���\n"
);
                set("value", 18000);
		set("for_bandit",1);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }

        init_blade(25);
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{

	victim->receive_wound("qi",5);
	return HIR "���泤�����һ���ɺ�Ļ��棬�ǿ���$n��ȫ��\n" NOR;

}
 
