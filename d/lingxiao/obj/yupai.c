//LUCAS 2000-6-18
// ������ hanyu pai

inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(HIW"������"NOR, ({"hanyu pai", "pai"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��ѩ�׵����ƣ�����������������Ѫ��\n");
//              set("no_drop", "�������������뿪�㡣\n");
                set("material", "yu");
        }
}

