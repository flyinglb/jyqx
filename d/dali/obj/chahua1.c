//chahua1.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
        set_name(HIY"������"NOR, ({"cha hua", "hua"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ��ʢ���Ĳ軨������ɫ��һ����ʮ���֡���ʮ��ѧʿ����һɫ��
ƫ���ǲ�����������������ٻ��磬�������д���С����������ʩ
Ч򭣬ѧ��ʮ��ѧʿ��ȴ���ǲ��񣬺��Ƹ���ƿ�׵��ᶡ��\n");
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
