// yitian-jian ���콣

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("���콣",({ "yitian jian", "yitian", "sword", "jian" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 10000);
                set("material", "steel");
                set("no_drop", "1");
                set("long", "����һ���ĳ������ĹŽ��������Ͻ�˿���������֡����족��\n"
                        "����������������һ����������δ���ʣ��ѿɼ��䲻����\n");
                set("wield_msg", HIY "$N��ৡ���һ�����$n���˸�������ֻ���������㣬\n"
                        "��ɫ���ƣ�������콣����̴��ľ���ơ�$Nһʱ��֪���롣\n"NOR);
                set("unwield_msg", HIY "$N��ľ�����뽣�ʡ�\n" NOR);
        }
        init_sword(50);
        setup();
}
