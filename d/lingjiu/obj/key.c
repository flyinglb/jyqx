//key.c
inherit ITEM;
void create()
{
        set_name( "Կ��", ({ "key"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����ͨ��ͭԿ�ס�\n");
                set("value", 0);
                set("material", "iron");
        }
}
