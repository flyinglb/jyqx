// tongbo.c
//

inherit ITEM;

void create()
{
        set_name("ͭ��", ({ "tongbo" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Խ��������ͭ�ࡣ\n");
                set("value", 50);
        }
        setup();
}
