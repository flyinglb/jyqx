// weapon: hanyan.c
// by mei
#include <weapon.h>
inherit CLUB;
void create()
{
        set_name("旱烟袋", ({ "han yandai", "yandai" }) );
        set_weight(1500);
                set("flag",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根旱烟袋，似乎威力不大。\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_club(15,2);
        setup();
}
