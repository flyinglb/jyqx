// yuxiao.c
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
    set_name(HIW "��" NOR, ({"yu axe","axe"}));
    set_weight(500);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ���ð������ɵĸ�ͷ��\n");
        set("value", 10000);
        set("flag",1);
        set("material", "bamboo");
        set("wield_msg", "$N�ӱ��ϰγ�һ��"+HIW+"��"+NOR+"���������С�\n");
        set("unwield_msg", "$N��һ��"+HIW+"��"+NOR+"���ڱ��ϡ�\n");
      }  
    init_axe(50,1);
    setup();
}   
