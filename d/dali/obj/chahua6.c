//chahua6.c
#include <ansi.h>
#include <armor.h>;
inherit HEAD;

void create()
{
        set_name(MAG"��"WHT"����"HIR"��"NOR, ({"cha hua", "hua"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ��軨��ͬ�꿪�����仨�����仨��"MAG"��ɫ"NOR"�����������׿ͣ�"WHT"��
ɫ"NOR"�ߴ�֮���������"HIR"��ɫ"NOR"����޶���С�����Ǻ��Ů�������ɫ
��ͬ��������״��䲻ͬ���������\n");
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


