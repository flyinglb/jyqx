// black-sword.c 
// By Winzip 200.1.21 

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIY"��ʥ��"NOR, ({ "shan sword", "sword","jian" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIB"���ǵ���������ʥ�����������ı�����\n"NOR);
                set("value", 20000);
                set("material", "steel");
                set("wield_msg", HIR"$N��ৡ���һ�����һ��$n"NOR HIR"��������,����е�ʱһ�����·���������һ�㣡\n"NOR);
                set("unwield_msg", HIR"$N�����е�$n"NOR HIR"��������Ľ��ʣ����Ҳ��֮һ����\n"NOR);
        }
        init_sword(80);
        setup();
}

