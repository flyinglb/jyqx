// tonghao.c
//

inherit ITEM;

void create()
{
        set_name("ͭ��", ({ "tonghao" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѽ��������ͭ�š�\n");
                set("value", 50);
        }
        setup();
}
