//LUCAS 2000-6-18
// yujing.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW"������"NOR, ({"bingpo yujing", "yujing"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "�������꺮����������ɵı�����,����ȥ�����͸,ɢ���������ĵĹ�â��\n");
                set("unit", "��");
                set("value", 70000);
        }
}

