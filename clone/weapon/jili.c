// jili.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIB"����޼"NOR, ({ "du jili", "jili" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("value", 0);
                set("base_unit", "ö");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "iron");
                set("long", HIG"����޼�Ǵ㶾�����������С����������Ĺ⡣\n"NOR);
                set("wield_msg", HIC"$NѸ�ٵش���������һЩ����޼���������оʹ�������\n"NOR);
                set("unwield_msg",HIC"$N������ʣ�µĶ���޼һ���Ͳ����ˡ�\n"NOR);
        }
        set_amount(50);
        init_throwing(50);
        setup();
}
