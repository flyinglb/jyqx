// blade.c
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW "��" NOR, ({ "yu blade","blade" }) );
    set_weight(4000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 20000);
        set("flag",2);
        set("material", "iron");
                set("long", "����һ���ð����̶��ɵ��񵶣�����΢΢͸��һ�ɺ�����\n");
                set("wield_msg", "$N���һ��$n��������\n");
        set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
    }
    init_blade(25,2);
    setup();
}
