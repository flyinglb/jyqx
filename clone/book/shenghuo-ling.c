// shenghuo-ling ʥ����

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("ʥ����",({ "shenghuo ling", "shenghuo", "ling" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 10000);
                set("material", "steel");
//                set("no_drop", "1");
                set("long", "����һ�����������ĺ��ƣ��ǽ�������ʵؼ�Ӳ�ޱȣ�\n"
                            "��͸���������������л�����ڣ�ʵ��������ӳ�⣬��\n"
                            "ɫ��á����Ͽ̵��в��ٲ�˹���֡� \n");
                set("wield_msg", HIY "$N��ৡ���һ������������һƬ����������������С�\n");
                set("unwield_msg", HIY "$N��ʥ���������䡣\n" NOR);
        }
        set("skill", ([
                "name"        : "shenghuo-ling",
                "exp_required":  50000,
                "jing_cost"   :  40,
                "difficulty"  :  30,
                "max_skill"   :  200,
                "min_skill"   :  100
        ]) );
        init_sword(50);
        setup();
}
