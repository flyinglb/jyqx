// cuiyu.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
        set_name(HIG"����"NOR, ({"cui yu", "yu"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", 
"һ֧���̵���ë��\n");
                set("value", 800);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 10);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}
