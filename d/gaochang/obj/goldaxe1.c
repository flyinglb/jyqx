// yuxiao.c
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
    set_name(YEL "�ƽ�" NOR, ({"axe","gold axe"}));
    set_weight(210000);

    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ��"+YEL+"�ƽ�"+NOR+"����ĸ�ͷ��\n");
        set("value", 500000);
        set("material", "gold");
        set("get_��1",1);
        set("weapon_prop/dodge", 50);
        set("wield_msg", "$N�ӱ��ϰγ�һ��"+YEL+"�ƽ�"+NOR+"���������С�\n");
        set("unwield_msg", "$N��һ��"+YEL+"�ƽ�"+NOR+"���ڱ��ϡ�\n");
      }  
    init_axe(500,1);
    setup();
}   
