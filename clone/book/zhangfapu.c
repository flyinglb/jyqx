// zhangfapu.c ����Ʒ���
// By Lgg,1998.9

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"����Ʒ���" NOR, ({ "haotian-pu","pu", }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("unit", "��");
             set("long",
        "����һ�����ƾɵ��飬�����������һЩС�˻���ȭ�ŵ�ͼ�Ρ�\n",
         );
         set("value", 0);
         set("material", "paper");
         set("skill", ([
                        "name":       "haotian-zhang",
                        "exp_required" : 10000,
                        "jing_cost":  30,
                        "difficulty": 20,
                        "max_skill":  80
                ]) );
        }
}
