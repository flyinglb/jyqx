// zhaoda.c 赵大

inherit NPC;
inherit F_UNIQUE;

int ask_job();
void do_dest(object ob);

void create()
{
        set_name("赵大", ({ "zhao da", "zhao" }));
        set("long", "他大约三十多岁，精明能干，笑嘻嘻的和蔼可亲。但却嫉恶如仇，性如烈火。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 35);
        set("con", 27);
        set("dex", 28);

        set("max_qi", 2000);
        set("qi", 2000);
        set("max_jing", 2000);
        set("jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 3000000);
        set("score", 60000);

        set_skill("force", 150);
        set_skill("taiji-shengong", 150);
        set_skill("dodge", 150);
        set_skill("lingxu-bu", 150);
        set_skill("unarmed", 150);
        set_skill("taiji-quan", 200);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 100);
        set_skill("literate", 100);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "lingxu-bu");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        create_family("侠客岛", 2, "弟子");

        set("inquiry",([
                "job" : (:ask_job:),
                "工作" : (:ask_job:),
        ]) );

        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_move :),
        }));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

int ask_job()
{
        object *all, me , who, where;
        string str;
        int me_exp, who_exp, i;
        me = this_player();
        me_exp = me->query("combat_exp");
        
        if(me_exp < 500000) {
                tell_object(me,name() +"冷笑着对你说到：“你还是回家多练几年在出来吧。”\n");
                return 1;
        }
        
        if(me->query("zhao_job/bonus") > 0) {
                str = me->query("zhao_job/name");
                tell_object(me,name() +"冷笑着对你说到：“上次杀"+str+"的事好象你还没办完吧。”\n");
                return 1;
        }
        
        if(me->query("qian_job/bonus") > 0
        || me->query("quest")) {
                tell_object(me,name() +"冷笑着对你说到：“你先去忙完自己的事吧。”\n");
                return 1;
        }
        all = livings();
        for(i=0; i<sizeof(all); i++) {
                if( all[i]->query("family/family_name") == "侠客岛" ) continue;
                if( all[i]->query("shen_type") == me->query("shen_type") ) continue;
                if( userp(all[i]) ) continue;
                where = environment(all[i]);
                if( !objectp(where) ) continue;
                if( (int)where->query("no_fight") ) continue;

                who_exp = all[i]->query("combat_exp");
                if( (who_exp < me_exp-me_exp/100*20 ) 
                || (who_exp > me_exp+me_exp/100*20 ) ) continue;
                
                who = all[i];
                break;
        }
        
        if(!objectp(who)) {
                tell_object(me,name() +"对你说到：“现在没什么事可以给你做。”\n");
                return 1;
        }
        
        me->set("zhao_job/name", who->name());
        
        if(who_exp > me_exp)
                me->set("zhao_job/bonus", 2);
        else 
                me->set("zhao_job/bonus", 1);
        tell_object(me,name() +"对你说到：“好吧，你去帮我把"+who->name()+"给杀了。”\n");
        return 1;
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id")) {
                if( undefinedp(who->query("zhao_job")) ) {
                        tell_object(who, name()+"笑道：那我可就不客气了。\n");
                } else if ( ob->value() < 5000) {
                        tell_object(who, name()+"哼的一声说道：这点钱可不够我们开销的！\n");
                } else {
                        tell_object(who, name()+"笑道：那好，咱们买卖不成仁义在。想讨差使再找我吧！\n");
                        who->delete("zhao_job");

                }
                call_out("do_dest", 1, ob);
                return 1;
        } else {
                tell_object(who, name()+"说道：这不是我想要的。\n");
                call_out("do_dest", 1, ob);
                return 0;
        }
}

void do_dest(object ob)
{
        if(!objectp(ob)) return;
        ob->move(VOID_OB);
        destruct(ob);
}
