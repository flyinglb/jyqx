// jinyantu.c ����ͼ��
// By Lgg,1998.9

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"����ͼ��" NOR, ({ "jinyan-tu","tu", }));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("unit", "��");
             set("long",
        "���Ǳ�����ͨ���飬�����������һЩС�˷����ͼ�Ρ�\n",
         );
         set("value", 0);
         set("material", "paper");
         set("skill", ([
                        "name":       "jinyan-gong",
                        "exp_required" : 10000,
                        "jing_cost":  25,
                        "difficulty": 18,
                        "max_skill":  60
                ]) );
        }
}
