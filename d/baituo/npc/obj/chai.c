//key.c
inherit ITEM;
void create()
{
        set_name( "��", ({ "chai"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��ľ��\n");
                set("value", 0);
                set("material", "wood");
              }
}
