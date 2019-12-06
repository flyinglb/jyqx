
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name(HIR "����" NOR, ({ "xiang nang", "nang" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set("material", "silk");
                set("armor_type", "married");
                set("armor_prop/armor",0);
                set("no_get",1);
                set("no_drop",1);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

void init()
{
        object ob = this_player();

        if (environment() == ob) {
                if (ob->query("gender") == "Ů��") {
                        set_name(HIC "����" NOR, ({ "yu pei", "yupei", "yu", "pei" }) );
                        set("unit", "��");
                        set("material", "jade");
                }
                if (!ob->query("marry/id") || !ob->query("marry/name")) {
                        ob->delete("marry");
                        call_out("lost", 1, ob);
                        return;
                }
                set("long", "������"
                        + (ob->query("gender") == "Ů��"?"�๫":"����")
                        + "����Ķ����������"
                        + (ob->query("gender") == "Ů��"?"��":"��")
                        + "��һ��С�֣���"
                        + ob->query("marry/name") + "����\n");
                wear();
        }
}

void lost(object ob)
{
                tell_object(ob, HIB "\n����Լ������һ������Ҫ�Ķ�����ʧ�ˣ�\n\n" NOR);
                destruct(this_object());
}

int unequip()
{
        object ob = environment();

        if (ob && ob->query("marry/id") && ob->query("marry/name"))
                return notify_fail("�㲻��ж����Ķ������\n");

        return ::unequip();
}

