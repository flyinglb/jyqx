// yunvjing1.c ��Ů�ľ���
// By Lgg,1998.9

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIM "��Ů�ľ��ϲ�" NOR, ({ "yunv-jing1", "jing1", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("unit", "��");
             set("long",
        "����һ��д�ڱ����ϵ��顣������д�� ��Ů�ľ����ϡ���\n",
         );
         set("value", 0);
         set("material", "silk");
         set("skill", ([
                        "name":       "yunv-xinfa",
                        "exp_required" : 30000,
                        "jing_cost":  40,
                        "difficulty": 30,
                        "max_skill":  80
                ]) );
        }
}
