// zhifapu.c һ��ָ����
// By Lgg,1998.9

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(YEL"һ��ָ����" NOR, ({ "yiyang-pu","pu", }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("unit", "��");
             set("long",
        "����һ��д��˿�ϵ��飬��������һλ������ʿ������ָָ����յı�Ӱ��\n",
         );
         set("value", 0);
         set("material", "silk");
         set("skill", ([
                        "name":       "sun-finger",
                        "exp_required" : 150000,
                        "jing_cost":  35,
                        "difficulty": 25,
                        "max_skill":  150
                ]) );
        }
//        set("no_drop", "�书�ؼ��ɲ�����㶪����\n");
        set("no_give", "�����������������ˡ�\n");
}
