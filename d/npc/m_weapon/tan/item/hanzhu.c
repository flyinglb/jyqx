//yuzhu.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"��˿����"NOR, ({ "han zhu","zhu"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����˿����ͨ�徧Ө΢΢�����̹⾧Ө��͸������ˮ��\n��ɵģ�����������������ƺ�����������ľ��ò��ϡ�\n");
                set("value", 0);
                set("material", "bamboo");
              }
}
void owner_is_killed()
{
        destruct(this_object());
}
