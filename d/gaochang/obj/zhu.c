//mingzhu.c
inherit ITEM;
void create()
{
        set_name(HIW "ҹ����" NOR, ({ "ming zhu" ,"zhu", }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�ź������Ϻ����飬����ֵ����Ǯ��\n");
                set("value", 100000);
                set("material", "iron");
              }
}

