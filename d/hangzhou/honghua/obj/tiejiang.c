// tiejiang.c
#include <weapon.h>
#include <ansi.h>
inherit CLUB;

void create()
{
        set_name("����", ({ "tie jiang", "jiang" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������ٿ���ü���������ǳ��أ��ɹ�����Ƭ���ˡ�\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_club(30);
        setup();
}

