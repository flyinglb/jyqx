//LUCAS 2000-6-18
// ganjiang.c 
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name( HIC "�ɽ�" NOR , ({ "ganjiang", "jian" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����Ǻպ������ĸɽ�,����������͸��һ������,��ϸ����,ֻ��һ����ɱ֮��ɭ�Ȼ��ɢ��\n");
                set("value", 20000);
                set("material", "steel");
                set("weapon_prop/personality", 8);
                set("wield_msg", "$N��ৡ���һ�����һ��$n��������,��ʱ��ɳ����,��������,��������塣\n");
                set("unwield_msg", "$N�����е�$n��ؽ���,һ���ӷ�ƽ�˾�,������\n");
        }
        init_sword(100);
        setup();
}

