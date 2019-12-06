// liwu.c
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        
}


void create()
{
set_name("礼物", ({"liwu"}));
        set("unit", "帖");
        set("long", "这是新金庸群侠为新玩家准备的礼物，\n
                        上面写着"+HIY"欢迎您加入〖新金庸群侠〗的武侠世界!"NOR+"\n");
    set("no_give", "不要动歪脑筋哟!\n");
        set("value",100);
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="liwu")
        {
                me->add("max_neili",100);
                me->add("combat_exp",10000);
                me->add("max_jingli",20);
                me->add("potential",3000);
                me->set("neili",me->query("max_neili"));
                me->set("eff_qi",me->query("max_qi"));
                me->set("qi",me->query("eff_qi"));
                message_vision("$N吃下这个"+HIR"礼物"NOR+",有一种说不出的的"+HIB"舒服"NOR+"感!\n",me);

                destruct(this_object());
        }
        return 1;
}

