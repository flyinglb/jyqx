//LUCAS 2000-6-18
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;


string *names = ({
HIW"÷��"NOR,
HIG"÷��"NOR,
CYN"÷��"NOR,
HIC"÷��"NOR,
HIY"÷��"NOR,
HIR"÷��"NOR,
});
void create()
{
        int i = random(sizeof(names));
        set_name(names[i], ({"mei ban","nam"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ƭ");
                set("long", 
              "һƬ�ոմ�����Ʈ���÷�ꡣ\n");
                set("value", 80);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}

