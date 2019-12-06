// book4.c
inherit ITEM;

void create()
{
    set_name("���", ({ "zhu jian", "jian"}));
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long",
           "��Щ����Ѿ���������̫���ˣ�����һ�������ͻ�ɢ����\n�㷢������д��һЩ��ֵ�...��\n");
        set("value", 500);
        set("material", "stone");
       set("no_get",1);
                setup ();
    }
}
void init()
{
        add_action("do_study", "study");
}


int do_study(string arg)
{
        object me;
        int    jing_cost;
        me = this_player();

        if (!me->query_temp("���"))
                     return notify_fail("��Ҫ��ʲô1��");
                if ( !arg || ( arg != "zhu jian" ) )
               return notify_fail("��Ҫ��ʲô2��");

        if ( (int)me->query_skill("literate", 1) < 1){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if ( (int)me->query_int() < 55){
                write("������Բ�������ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        jing_cost = me->query("max_jing")/5;
        if((int)me->query("jing") < jing_cost){
                write("�㿴�˿����ϵ�����ƺ������һЩ������\n");
                return 1;
        }
        me->receive_damage("jing", jing_cost );
        me->delete_temp("stone_learned");

        message_vision("$N��ר���ж����ϵ����\n", me);
        
        write("����������ĥ��һ�ض�����������\n");

        if ( (int)me->query_skill("axe", 1) < 1000 && random(10)>3 ){
                        me->improve_skill("axe", me->query_int());
                        me->set_temp("stone_learned",1);
                }
        return 1;
}
