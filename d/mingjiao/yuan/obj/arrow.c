// arrow.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIC"��β��"NOR, ({ "fengwei jian", "arrow" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("base_unit", "֧");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "iron");
                set("long", "��β������������Ƶ����͡�\n");
                set("wield_msg", HIC"$NѸ�ٵشӼ����г��һ����β�����������֣��ʹ�������\n"NOR);
                set("unwield_msg",HIC"$N������ʣ�µķ�β���Żؼ����С�\n"NOR);
        }
        set_amount(20);
        init_throwing(25);
        setup();
}
