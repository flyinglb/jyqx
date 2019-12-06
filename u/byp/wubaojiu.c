//wubaojiu.c 五宝花蜜酒

inherit ITEM;

void create()
{
	set_name(HIY"五宝花蜜酒"NOR, ({"wubao huamijiu", "huamijiu", "jiu"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一瓶五毒教独有的"HIY"五毒花蜜酒"NOR"，瓶子里传出阵阵花香。\n");
		set("unit", "瓶");
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
        
        if(me->query("family/family_name") != "五毒教") {
                if ((int)me->query_condition("wubao_poison") > 0) {
                        me->apply_condition("wubao_poison",
                        me->query_condition("wubao_poison") - 10 );
                }
                message_vision("$N拿起" + name() + "咕噜噜地喝了几口，顿时觉得精神很多。\n", me);
        } else {
                object *who;
                int i;
                who = all_inventory(environment(me));
                for(i=0; i<sizeof(who); i++) {
                        if(environment(me)->query("no_fight")) break ;
                        if( !living(who[i]) || who[i]== me ) continue;
                        if(who[i]->query("family/family_name") == "五毒教") continue;
                        if(who[i]->query_condition("wubao_poison") >= 30) continue;
                        who[i]->apply_condition("wubao_poison",
                                (int)who[i]->query_condition("wubao_poison") + 10 );
                }                        
                message_vision("$N拿起" + name() + "咕噜噜地喝了几口，顿时满屋子花香四溢。\n", me);
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
                message_vision("$N把" + name() + "喝得干干净净，随手就把酒瓶给扔了。\n", me);
                destruct(this_object());
        }
        return 1;
}
