//chahua3.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
        set_name(HIG"ʮ��̫��"NOR, ({"cha hua", "hua"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ��軨��֦�Ϲ���ʮ���仨�������ɫ��ͬ�����ް�ֻ��ӡ���
��ʮ���仨��״��䲻ͬ�����и��������ʱ�뿪��лʱ��л��
�ǽ�����ʮ��ѧʿ�����²軨��Ʒ��\n");
                set("value", 90);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}

