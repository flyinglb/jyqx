// /u/beyond/mr/obj/lingbai-xiaren ���Ϻ��
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW"���Ϻ��"NOR, ({"lingbai xiaren", "xiaren"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ɫ��õ�壬�������۵����Ϻ�ʡ�\n");
                set("unit", "��");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}

