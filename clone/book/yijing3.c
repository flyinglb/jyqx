//yijing3.c

inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name(HIY"���׾�ϵ��ƪ��"NOR, ({ "yijing xici","yijing3", }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
        "����һ���ñ���д�ɵ��顣���飺���׾�ϵ��ƪ����\n"
        "��Ƥ���ƣ������Ѿ�����ܾ��ˡ�\n",

        );
                set("value", 0);
                set("material", "silk");
                set("skill", ([
                        "name":       "qimen-wuxing",
                        "jing_cost":  35,
                        "difficulty": 20,
                        "max_skill":  100,
                        "min_skill":  75
                ]) );
        }
}
