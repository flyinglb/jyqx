// yunvjing2.c ��Ů�ľ���
// By Lgg,1998.9

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIM "��Ů�ľ��²�" NOR, ({ "yunv-jing2", "jing2", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("unit", "��");
             set("long",
        "����һ��д�ڱ����ϵ��顣������д�� ��Ů�ľ����¡���\n",
         );
         set("value", 0);
         set("material", "silk");
         set("skill", ([
                        "name":       "yunv-xinfa",
                        "exp_required" : 65000,
                        "jing_cost":  42,
                        "difficulty": 32,
                        "max_skill":  160
                ]) );
        }
}
