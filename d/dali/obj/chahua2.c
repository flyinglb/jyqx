//chahua2.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
        set_name(HIR"ʮ��ѧʿ"NOR, ({"cha hua", "hua"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ��軨��֦�Ϲ���ʮ�˶仨�������ɫ��ͬ��"HIR"��"NOR"�ľ���ȫ�죬"MAG"��"NOR"
�ı���ȫ�ϣ����ް�ֻ��ӡ�����ʮ�˶仨��״��䲻ͬ�����и�
�������ʱ�뿪��лʱ��л�������²軨�ļ�Ʒ��\n");
                set("value", 100);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}
