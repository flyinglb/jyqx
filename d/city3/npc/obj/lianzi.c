// tielianzi.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIC"������"NOR, ({ "tie lianzi", "lianzi","tie" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("value", 0);
                set("base_unit", "��");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "iron");
                set("long", HIW"��������һ������ȡʤ�İ��������ߵߵġ�\n"NOR);
                set("wield_msg", HIC"$NѸ�ٵشӰ��������ͳ�һЩ�����ӣ��������оʹ�������\n"NOR);
                set("unwield_msg",HIC"$N������ʣ�µ������Ӿ����Żذ������С�\n"NOR);
             }
        set_amount(50);
        init_throwing(25);
        setup();
}
