// /u/beyond/obj/chahua1.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>                     
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIR"���˽ڵ�õ��"NOR,({ "mei gui", "flower" }) );
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "plant");
                set("long", "����һ�����˽��͸����˵�õ�塣\n");
                set("wear_msg", "");
                set("unequip_msg", "$N���������$n��\n");
                set("armor_prop/armor", 0);
        }
           
        setup();
}

int wear()
{
        object me = environment();
        int ret;

        message_vision("$N�ó�һ��" + this_object()->query("name") + "���������", me);
        if (ret=::wear()) {
                if (me->query("gender") == "����")
                        message_vision("�о��Լ�����ܰ��\n", me);
                else if (me->query("gender") == "Ů��")
                        message_vision("�о������˶��Լ��Ĺ��ģ�\n", me);
                else
                        message_vision("��һ���������ĵļһ\n", me);
        }
        return ret;
}

