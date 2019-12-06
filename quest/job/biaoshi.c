#include <ansi.h>
inherit NPC;

int do_copy(object me);
int go_back(object me);
void copy_player(object me);
void random_perform();
void random_exert();

object me;

void create()
{
        set_name("护镖镖师", ({ "biaoshi"}));
        set("gender", "男性");
        set("age", random(15) + 30);
        set("no_get",1);
        set("no_quest", 1);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "镖局的镖师。\n");
        set("combat_exp", 1080000 + random(4000000)); 
        set("attitude", "friendly");
        set_skill("force", 150);
        set_skill("sword", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("blade", 150);
        set_skill("lingboweibu",150);
        set_skill("wuhu-duanmendao",150);
        
        map_skill("dodge","lingboweibu");
        map_skill("blade","wuhu-duanmendao");

        set("max_qi", 2450); 
        set("eff_jingli", 2400); 
        set("neili", 5700); 
        set("max_neili", 5700);
        set("jiali", 60);
        
        setup();

//        carry_object(__DIR__"obj/blade")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        
        call_out("do_dest",300);
}

void die()
{
        int pot,exp;
        object killer, ob;
        
        ob = this_object();
        exp= random(200)+800;
        pot= exp/7;
        
        if ( killer == me ){
                if(objectp(killer = query_temp("last_damage_from")))
                {
                        tell_object(killer,"你被奖励了\n"+chinese_number(exp)+"点实战经验\n"
                        +chinese_number(pot)+"点潜能\n");
        
                        killer->add("combat_exp",exp);
                        killer->add("potential",pot);
                }
        }
        ::die();
        destruct(ob);

        return;
}

/*
int checking(object ob, object me)
{
        if(!me || !present(me, environment(ob)))
                go_back(me);
        else call_out("checking", 2, ob, me);
                return 1;
}

int do_copy(object me)
{
        object ob;
        ob = this_object();

        if(!me->query_temp("xx_rob")){
                go_back(me);
                return 0;
        }
        me->add_temp("biaoshi", 1);
        
        checking(ob, me);    
        call_out("do_back", 350,  ob);  
        return 1;
}
*/

void copy_player(object who)
{
        object me;//, weapon;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname, w_name; // w_name 兵器名称
        int i, temp, damage; 

        me = this_object();
        hp_status = who->query_entire_dbase();
        set("combat_exp",hp_status["combat_exp"]+hp_status["combat_exp"]/10*2);

        if ( mapp(skill_status = query_skills()) ) {
                skill_status = query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        delete_skill(sname[i]);
                }
        }
        if ( mapp(skill_status = who->query_skills()) ) {
                skill_status = who->query_skills();
                sname  = keys(skill_status);
                for(i=0; i<sizeof(skill_status); i++) {
                        set_skill(sname[i], to_int(ceil(pow(to_float(query("combat_exp"))*10.0, 0.333333))));
                }
        }
        if ( mapp(map_status = query_skill_map()) ) {
                mname  = keys(map_status);
                temp = sizeof(map_status);
                for(i=0; i<temp; i++) {
                        map_skill(mname[i]);
                }
        }
        if ( mapp(map_status = who->query_skill_map()) ) {
                mname  = keys(map_status);
                for(i=0; i<sizeof(map_status); i++) {
                        map_skill(mname[i], map_status[mname[i]]);
                }
        }
        if ( mapp(prepare_status = query_skill_prepare()) ) {
                pname  = keys(prepare_status);
                temp = sizeof(prepare_status);
                for(i=0; i<temp; i++) {
                        prepare_skill(pname[i]);
                }
        }
        if ( mapp(prepare_status = who->query_skill_prepare()) ) {
                pname  = keys(prepare_status);
                for(i=0; i<sizeof(prepare_status); i++) {
                        prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }

        w_name = who -> query_temp("combating_actions_skill_type");

        for(i=0;i<7;i++)
        {
//        weapon_name = weapon_id[i];
//        w_id = weapon_name["w_id"];
                if(w_name == "blade" )
                        {
//                                weapon = new(__DIR__"obj/blade");
//                                weapon -> move(me);
                                carry_object(__DIR__"obj/blade")->wield();
//                                command("wield blade");
                                damage = who -> query_temp("apply/damage");
                                me -> set("weapon_prop/damage", damage);
                                return;
                        }
                else if(w_name == "sword" )
                        {
//                                weapon = new(__DIR__"obj/sword");
//                                weapon -> move(me);
                                carry_object(__DIR__"obj/sword")->wield();
//                                command("wield sword");
                                damage = who -> query_temp("apply/damage");
                                me -> set("apply/damage", damage);
                                return;
                        }
                else if(w_name == "axe" )
                        {
//                                weapon = new(__DIR__"obj/axe");
//                                weapon -> move(me);
                                carry_object(__DIR__"obj/axe")->wield();
//                                command("wield axe");
                                damage = who -> query_temp("apply/damage");
                                me -> set("apply/damage", damage);
                                return;
                        }
                else if(w_name == "club" )
                        {
//                                weapon = new(__DIR__"obj/club");
//                                weapon -> move(me);
                                carry_object(__DIR__"obj/club")->wield();
//                                command("wield club");
                                damage = who -> query_temp("apply/damage");
                                me -> set("apply/damage", damage);
                                return;
                        }
                else if(w_name == "bian" )
                        {
//                                weapon = new(__DIR__"obj/bian");
//                                weapon -> move(me);
                                carry_object(__DIR__"obj/bian")->wield();
//                                command("wield bian");
                                damage = who -> query_temp("apply/damage");
                                me -> set("apply/damage", damage);
                                return;
                        }
                else if(w_name == "staff" )
                        {
//                                weapon = new(__DIR__"obj/staff");
//                                weapon -> move(me);
                                carry_object(__DIR__"obj/staff")->wield();
//                                command("wield staff");
                                damage = who -> query_temp("apply/damage");
                                me -> set("apply/damage", damage);
                                return;
                        }

        }

        
        set("str", hp_status["str"]+random(10));
        set("int", hp_status["int"]+random(10));
        set("con", hp_status["con"]+random(10));
        set("dex", hp_status["dex"]+random(10));
        set("max_qi",    hp_status["max_qi"]+hp_status["max_qi"]/5);
        set("eff_qi",    query("max_qi"));
        set("qi",        query("max_qi"));
        set("max_jing",  hp_status["max_jing"]+hp_status["max_jing"]/5);
        set("eff_jing",  query("max_jing"));
        set("jing",      query("max_jing"));
        set("max_neili", hp_status["max_neili"]+hp_status["max_neili"]/2);
        set("neili",     query("max_neili"));
        set("max_jingli",hp_status["max_jingli"]+hp_status["max_neili"]/2);
        set("jingli",query("max_jingli"));
//        set("jiali",  query_skill("force") / 8 );
        set("jiali",     (who->query("jiali")>0)?who->query("jiali"):query_skill("force")/8 );
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: random_perform :),
                (: random_perform :),
                (: random_perform :),
                (: random_perform :),
                (: random_perform :),
                (: random_perform :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: random_exert :),
                (: random_exert :),
        }) );
}

void random_perform()
{
        string action, *mlist, *alist;
        mapping map_skills;
        int index;
        map_skills = query_skill_map();
        if( !map_skills ) return;
        mlist = keys(map_skills);
        if( !mlist ) return;
        alist = get_dir(SKILL_D(map_skills[mlist[random(sizeof(mlist))]])+"/");
        if( !alist ) return;
        index = random(sizeof(alist));
        if( !sscanf(alist[index],"%s.c",action) )
                return;
        action = alist[index]+"."+action;
        perform_action(action);
}

void random_exert()
{
        string action, skills, *alist;
        skills = query_skill_mapped("force");
        if( !skills ) return;
        alist = get_dir(SKILL_D(skills+"/"));
        if( !alist ) return;
        if( !sscanf(alist[random(sizeof(alist))],"%s.c",action) )
                return;
        exert_function(action);
}

/*
int go_back(object me)
{
        object ob = this_object();
        
        if(!objectp(present(me, environment(ob))))
        {
                destruct(ob);
                remove_call_out("do_back");
                message_vision("$N急急忙忙离开了。\n", ob);
                return 1;
        }
        remove_call_out("do_back");
        call_out("do_back", 30, me);
        return 0;
}
*/

void do_dest()
{
        object ob;
        ob = this_object();
        
        message_vision("$N急急忙忙离开了。\n", ob);
        destruct(ob);
        return;
}

void copy_weapon(object who)
{
        int damage, armor;
        object me;
        me = this_object();
                
        damage = who -> query_temp("apply/damage");
        armor = who -> query_temp("apply/amror");
        
        me ->set_temp("apply/damage",damage);
        me ->set_temp("apply/armor",armor);
        
        copy_weapon(who);
        copy_player(who);

//        if ( me -> query("hunmi"))
//        {
//                die(who);
//        }

}

