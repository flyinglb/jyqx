// yitian-jian ���콣

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("���콣",({ "yitian jian", "yitian", "sword", "jian" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000000);
                set("material", "steel");
                set("long", "����һ���ĳ������ĹŽ��������Ͻ�˿���������֡����족��
����������������һ����������δ���ʣ��ѿɼ��䲻����\n");
                set("wield_msg", HIY "$N��ৡ���һ�����$n���˸�������������â���£�
�����Ƿɡ� ....$N���ɵô��ĵ�����һ�����ƺ�����\n" NOR);
                set("unwield_msg", HIY "���콣����һ���׹⣬��ৡ��ط��뽣�ʡ�\n" NOR);
                set("unequip_msg", HIY "���콣����һ���׹⣬��ৡ��ط��뽣�ʡ�\n" NOR);
        }
        init_sword(1000);
        setup();
}

void init()
{
        if( wizardp(environment()) ) {
                set("value", 10000000);
                init_sword(1000);
        } else {
                set("value", 100);
                set("no_drop", "��˱���������������󰡡�\n");
                set("no_get", "���ˣ�������ĳ�����\n");

                init_sword(500);
        }
}
