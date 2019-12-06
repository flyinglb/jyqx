//hulu1.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("��«", ({"rhulu", "hu"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����ɫ�ĺ�«��\n");
                set("unit", "��");
                set("value", 100);
                set("max_liquid", 3);
        }
        // because a container can contain different liquid
        // we set it to contain water at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "ҩ��",
                "remaining": 3,
                "drunk_supply": 10,
        ]));
}

