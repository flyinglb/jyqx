
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "�ϵ��̲�", ({ "shangdeng yancao", "yancao" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "leather");           
        }
        setup();
}

