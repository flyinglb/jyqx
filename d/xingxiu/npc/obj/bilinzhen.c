// tielianzi.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIG"������"NOR, ({ "bilin zhen", "zhen" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("value", 0);
                set("base_unit", "ö");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "iron");
                set("long", HIG"�������������ɴ㶾�������볤������������Ĺ⡣\n"NOR);
                set("wield_msg", HIC"$NѸ�ٵش���������һЩ�����룬�������оʹ�������\n"NOR);
                set("unwield_msg",HIC"$N������ʣ�µı�����һ���Ͳ����ˡ�\n"NOR);
        }
        set_amount(50);
        init_throwing(50);
        setup();
}
