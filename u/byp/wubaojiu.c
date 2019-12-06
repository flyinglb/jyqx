//wubaojiu.c �屦���۾�

inherit ITEM;

void create()
{
	set_name(HIY"�屦���۾�"NOR, ({"wubao huamijiu", "huamijiu", "jiu"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һƿ�嶾�̶��е�"HIY"�嶾���۾�"NOR"��ƿ���ﴫ�������㡣\n");
		set("unit", "ƿ");
		set("value", 20000);
		set("max_capacity", 20);
		set("excessive", 6);
	}

}

void init()
{
        add_action("do_drink", "drink");
        add_action("do_drink", "he");
}

int do_drink(string arg)
{
        object me = this_player();
        
        if(!id(arg))
                return 0;
        if((arg != "wubao huamijiu") && (arg != "huamijiu") && (arg != "jiu"))
                return 0;
                
        if ((int)me->query_condition("snake_poison") > 0) {
                me->apply_condition("snake_poison",
                me->query_condition("snake_poison") - 10 );
        }
        if ((int)me->query_condition("wugong_poison") > 0) {
                me->apply_condition("wugong_poison", 
                me->query_condition("wugong_poison") - 10 );
        }
        if ((int)me->query_condition("zhizhu_poison") > 0) {
                me->apply_condition("zhizhu_poison",
                me->query_condition("zhizhu_poison") - 10 );
        }
        if ((int)me->query_condition("xiezi_poison") > 0) {
                me->apply_condition("xiezi_poison",
                me->query_condition("xiezi_poison") - 10 );
        }
        if ((int)me->query_condition("chanchu_poison") > 0) {
                me->apply_condition("chanchu_poison",
                me->query_condition("chanchu_poison") - 10 );
        }
        
        if(me->query("family/family_name") != "�嶾��") {
                if ((int)me->query_condition("wubao_poison") > 0) {
                        me->apply_condition("wubao_poison",
                        me->query_condition("wubao_poison") - 10 );
                }
                message_vision("$N����" + name() + "������غ��˼��ڣ���ʱ���þ���ܶࡣ\n", me);
        } else {
                object *who;
                int i;
                who = all_inventory(environment(me));
                for(i=0; i<sizeof(who); i++) {
                        if(environment(me)->query("no_fight")) break ;
                        if( !living(who[i]) || who[i]== me ) continue;
                        if(who[i]->query("family/family_name") == "�嶾��") continue;
                        if(who[i]->query_condition("wubao_poison") >= 30) continue;
                        who[i]->apply_condition("wubao_poison",
                                (int)who[i]->query_condition("wubao_poison") + 10 );
                }                        
                message_vision("$N����" + name() + "������غ��˼��ڣ���ʱ�����ӻ������硣\n", me);
        }
        me->add("water", 30);
        me->add("food", 10);
        me->add("neili",20);
        if(me->query("neili") > me->query("max_neili"))
                me->set("neili", me->query("max_neili"));
                
        me->add("qi",20);
        if(me->query("qi") > me->query("max_qi"))
                me->set("qi", me->query("max_qi"));
                
        add("max_capacity", -1);

        if(query("max_capacity") <= 0) {
                message_vision("$N��" + name() + "�ȵøɸɾ��������־ͰѾ�ƿ�����ˡ�\n", me);
                destruct(this_object());
        }
        return 1;
}
