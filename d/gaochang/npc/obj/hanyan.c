// weapon: hanyan.c
// by mei
#include <weapon.h>
inherit CLUB;
void create()
{
        set_name("���̴�", ({ "han yandai", "yandai" }) );
        set_weight(1500);
                set("flag",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����̴����ƺ���������\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_club(15,2);
        setup();
}
