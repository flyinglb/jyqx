// yuxiao.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name(HIW "��" NOR, ({"yu sword","sword"}));
    set_weight(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ�������������ɵı��������ƺ��ܴࡣ\n");
        set("value", 10000);
        set("flag",2);
        set("material", "bamboo");
        set("wield_msg", "$N�ӽ�������һ�Ѿ�Өͨ͸��"+HIW+"��"+NOR+"��\n");
        set("unwield_msg", "$N��"+HIW+"��"+NOR+"С������Ĳ�ؽ��ʡ�\n");
    }
    init_sword(50,2);
    setup();
} 
