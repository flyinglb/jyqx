// by mei
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name("��˿��", ({"rousisuo", "silk"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long", "����һ��΢ϸ͸��, �����������ܲ����˿����\n");
        set("value", 100000);
        set("material", "leather");
        set("wield_msg", "$N���һ��$n���������С�\n");
        set("unwield_msg", "$N�������е�$n�������䡣\n");
        }
        init_whip(1,2);
        setup();
}
