// book4.c
inherit ITEM;

void create()
{
    set_name("���˵����", ({ "suiyu", "yu"}));
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long",
           "����һ�����˵����\n");
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
		int leiting;
        me = this_player();

        if (!me->query_temp("break_suiyu"))
		       return notify_fail("��Ҫ��ʲô��");
		
		if ( !arg || ( arg != "suiyu" ) )
                return notify_fail("��Ҫ��ʲô��");

        if ( (int)me->query_skill("literate", 1) < 1){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if ( (int)me->query_int() < 55){
                write("������Բ�������ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        leiting = me->query_skill("leiting-axe", 1);
        if( (int)me->query("combat_exp") < (int)leiting*leiting*leiting/20 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
		}
        jing_cost = me->query("max_jing")/5;
        if((int)me->query("jing") < jing_cost){
                write("�㿴�˿����ϵ������ƺ������һЩ������\n");
                return 1;
        }
        me->receive_damage("jing", jing_cost );
        me->delete_temp("stone_learned");

        message_vision("$N��ר���ж����ϵ�����\n", me);
        
        write("�����������ĥ��һ�ض�����������\n");
        if ( (int)me->query_skill("leiting-axe", 1) >= (int)me->query_skill("axe",1) ) return 1;

        if ( (int)me->query_skill("leiting-axe", 1) < 450 && random(10)>3 ){
                        me->improve_skill("leiting-axe", me->query_int());
                        me->set_temp("stone_learned",1);
                }
        return 1;
}

