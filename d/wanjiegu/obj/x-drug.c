// x-drug.c

inherit ITEM;

void create()
{
        set_name("�����Ϻ�ɢ", ({ "x-drug" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ǿ�ҵĴ�ҩ��\n");
                set("unit", "��");
                set("value", 0);
        }
}

