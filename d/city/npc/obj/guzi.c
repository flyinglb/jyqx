// guzi.c
#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("����", ({ "guzi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "���ӳ�����һ�ֶľ��⣬Ҳ��һ�ֽ���İ�����\n");
                set("unit", "��");
                set("base_unit", "ö");
                set("base_weight", 2);
                set("base_value", 10);
        }
        set_amount(200);
        init_throwing(2);
        setup();
}
