//xuantie.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(RED"ǧ����ľ"NOR, ({ "shen mu","mu"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��ǧ����ľ���������͸��ģ�����ȥʮ�ּ�Ӳ��\n"
		    "�ƺ�����������ľ��ò��ϡ�\n");
                set("value", 0);
                set("material", "wood");
              }
}

void owner_is_killed()
{
        destruct(this_object());
}
