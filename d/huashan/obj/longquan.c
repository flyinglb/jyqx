// youlong.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(CYN"��Ȫ��"NOR, ({ "longquan sword", "longquan", "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"���Ǳ�һ����֪���Ǳ�����������\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", 
"ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
        init_sword(60);
        setup();
}


