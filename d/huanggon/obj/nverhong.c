// nverhong.c Ů����

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("Ů����", ({"nver hong", "wine"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ̳�Ϻõ�Ů����,��������.\n");
                set("unit", "̳");
                set("value", 500);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name" : "Ů�����",
                "remaining": 3,
                "drunk_supply": 6,
        ]));
}

