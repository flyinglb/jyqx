
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIB"�����"NOR, ({ "jingtian bi", "sword","jian" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "�����쳤��Ϊʾ���ţ��Աʴ�����������\n");
                set("value", 150000);
                set("material", "steel");
                set("wield_msg", "$N�������һ֧$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���������С�\n"NOR);
        }
        init_sword(50);
        setup();
}

