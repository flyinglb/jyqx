// stone.c
inherit ITEM;

void create()
{
        set_name("ʯ��", ({"stone"}));
        set_weight(60);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��Сʯ�ӡ�\n");
                set("unit", "��");
                set("value", 0);
        }
}

