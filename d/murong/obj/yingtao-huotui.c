// /u/beyond/mr/obj/yingtao-huotui.c ӣ�һ���
// this is made by beyond
// update 1996.6.20
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(MAG"ӣ�һ���"NOR, ({"yingtao huotui", "huotui"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ɫ��õ�壬���ۿɿڵ�ӣ�һ��ȡ�\n");
                set("unit", "��");
                set("value", 150);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}

