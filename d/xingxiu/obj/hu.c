// item: /d/xingxiu/npc/obj/hu.c
// Jay 3/17/96

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("���̾ƺ�", ({"hu", "bottle"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������װ���̾ƵĴ�ƺ������װ�ðˡ������ľơ�\n");
                set("unit", "ֻ");
                set("value", 100);
                set("max_liquid", 15);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "���̾�",
                "remaining": 15,
                "drunk_supply": 6,
        ]));
}

