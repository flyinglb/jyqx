
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("����", ({ "jin zhen", "zhen" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ���ƳγεĽ��롣\n");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", 
"ֻ������쬡���һ����$N�ӷ�����һ���������ķָ��ʳָ�䡣\n");
                set("unwield_msg", "$N�����е�$n��ط��䡣\n");
        }
        init_sword(100,2);
        setup();
}
