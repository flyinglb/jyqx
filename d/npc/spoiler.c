//spoiler.c
//掠夺者

#pragma optimize
#pragma save_binary

inherit NPC;
inherit F_UNIQUE;

#ifndef EVENT_D
#define EVENT_D "/adm/daemons/eventd"
#endif

#define Delay 60

string *treasure = ({
        "/clone/book/bojuan",
        "/clone/book/jiuyin1",
        "/clone/book/jiuyin2",
        "/clone/book/qiankun_book",
        "/clone/book/six_book",
        "/clone/book/yijinjing",
        "/clone/book/zixia_book",
        "/d/city/npc/obj/pink_cloth",
        "/d/city/npc/obj/jisijia",
        "/d/city/npc/obj/goldring",
        "/d/city/npc/obj/yaoshi",
        "/d/city/npc/obj/tieshou",
        "/d/city/npc/obj/shouwu",
        "/d/city2/obj/baojia",
        "/d/city2/obj/bishou",
        "/d/city2/obj/diaopi",
        "/d/city2/obj/gaoyao",
        "/d/city2/obj/goldleaf",
        "/d/city2/obj/hlbian",
        "/d/city2/obj/shouzhuo",
        "/d/city2/obj/yaoshi",
        "/d/dali/npc/obj/doupeng",
        "/d/dali/npc/obj/guazi",
        "/d/dali/npc/obj/kenao",
        "/d/dali/npc/obj/lace",
        "/d/dali/npc/obj/mixian",
        "/d/dali/npc/obj/qiguoji",
        "/d/dali/npc/obj/qun",
        "/d/dali/npc/obj/tongqun",
        "/d/dali/npc/obj/ttoujin",
        "/d/dali/npc/obj/wchangqun",
        "/d/dali/npc/obj/yeerba",
        "/d/emei/obj/qingshui-hulu",
        "/d/emei/obj/ruanjian",
        "/d/emei/obj/tianxiang-gao",
        "/d/guanwai/npc/obj/cwbdao",
        "/d/gumu/npc/obj/junzijian",
        "/d/gumu/npc/obj/shunvjian",
        "/d/gumu/obj/ping",
        "/d/gumu/obj/ziwei",
        "/d/hangzhou/npc/obj/chicken",
        "/d/hangzhou/npc/obj/fish",
        "/d/hangzhou/npc/obj/geng",
        "/d/hangzhou/npc/obj/green_sword",
        "/d/hangzhou/npc/obj/jiuping",
        "/d/hangzhou/npc/obj/pork",
        "/d/hangzhou/npc/obj/shrimp",
        "/d/heimuya/npc/obj/card1",
        "/d/heimuya/npc/obj/card2",
        "/d/heimuya/npc/obj/card3",
        "/d/heimuya/npc/obj/card4",
        "/d/heimuya/npc/obj/yaoshi",
        "/d/heimuya/obj/heimu-ling",
        "/d/huanghe/npc/obj/shuikao",
        "/d/huashan/npc/obj/green_water_sword",
        "/d/huashan/obj/longquan",
        "/d/jinshe/obj/jinshe-jian",
        "/d/kunlun/npc/obj/diaopiyi",
        "/d/kunlun/npc/obj/shansword",
        "/d/kunlun/obj/jinshe",
        "/d/kunlun/obj/yinshe",
        "/d/lingjiu/npc/obj/baiyunwan",
        "/d/mingjiao/obj/yitianjian",
        "/d/meizhuang/obj/honghua",
        "/d/quanzhou/npc/obj/huoqiang",
        "/d/quanzhou/npc/obj/wodao",
        "/d/quanzhou/npc/obj/xiuhua",
        "/d/shaolin/obj/fumo-dao",
        "/d/shaolin/obj/jingang-zhao",
//      "/d/shaolin/obj/puti-zi",
        "/d/shenlong/obj/baihua",
        "/d/shenlong/obj/xionghuang",
        "/d/taohua/obj/xiang",
        "/d/wudujiao/npc/obj/chanchudu",
        "/d/wudujiao/npc/obj/jingou",
        "/d/wudujiao/npc/obj/shedu",
        "/d/wudujiao/npc/obj/skirt",
        "/d/wudujiao/npc/obj/wugongdu",
        "/d/wudujiao/npc/obj/xiezidu",
        "/d/wudujiao/npc/obj/zhizhudu",
        "/d/xiakedao/obj/mangguo",
        "/d/xiakedao/obj/zhutou",
        "/d/xiakedao/obj/shoupa",
        "/d/xiakedao/obj/xuantie",
        "/d/xingxiu/npc/obj/tongbo",
        "/d/xingxiu/npc/obj/tonggu",
        "/d/xingxiu/npc/obj/tonghao",
        "/d/xingxiu/npc/obj/wandao",
        "/d/xueshan/obj/niupidai",
        "/d/xueshan/obj/qingke-m",
        "/d/xueshan/obj/jinlun",
        "/kungfu/class/mingjiao/obj/yitian-jian",
});

string *random_id = ({
        "mask-man",
        "mengmian-ren",
        "spoiler",
        "wuzhe",
        "xiaosan",
        "asi",
        "wangze",
        "changchun",
        "daniu",
        "xiaogui",
});

void find_target();
object find_target_in(object env);
void back_home();
void copy_player(object who);
int check_inv(object who, string obid, string obfile);
object check_inv_in(object env, string obid, string obfile);
void check_env(object who, object what, string obfile);
void do_loot(object who, object what);
void random_perform();
void random_exert();

void find_target()
{
        object obj, *obs, *inv;
        int i, i1, j, j1, w, w1;

        if( is_fighting()
        || objectp(query("is_have_target"))
        || query("solw_find") > 0 ) {
                add("solw_find",-1);
//                EVENT_D->add_event(this_object(),"find_target");
                call_out("find_target",Delay);
                return;
        }
        CHANNEL_D->do_channel(this_object(),"debug","Spoiler start find target");

        w = -1; w1 = 0;
        obs = users();
        for(i=0,i1=sizeof(obs);i<i1;i++){
                if( !environment(obs[i]) ) continue;
                if( environment(obs[i])->query("no_fight") 
                || environment(obs[i])->query("sleep_room") ) continue;
//                if( obs[i]->is_fighting() ) continue;
                if( obs[i]->query_temp("in_sleeping") == 1 ) continue;
//                if( obs[i]->is_killing() ) continue;
                if( obs[i]->is_busy()
                && !obs[i]->query_temp("pending/exercising")
                && !obs[i]->query_temp("pending/respirate") ) continue;
                if( !inv = all_inventory(obs[i]) ) continue;
                for(j=0,j1=sizeof(inv);j<j1;j++) {
                        if( inv[j]->is_container() ) {
                                obj = find_target_in(inv[j]);
                        }
                        if( !objectp(obj) ) obj = inv[j];
                        w = member_array(base_name(obj),treasure);
                        if( w != -1  && random(10) < 6 ) {
                                do_loot(obs[i],obj);
                                w1=1;break;
                        }
                }
                if(w1) break;
        }
        if( !w1 )
        CHANNEL_D->do_channel(this_object(),"debug","Spoiler not target");
//        EVENT_D->add_event(this_object(),"find_target");
        call_out("find_target",Delay);
}

object find_target_in(object env)
{
        object obj, *inv;
        int i, i1;
        if( !objectp(env) ) return 0;
        inv = all_inventory(env);
        for(i=0,i1=sizeof(inv);i<i1;i++) {
                if( inv[i]->is_container() ) {
                        obj = find_target_in(inv[i]);
                        if( objectp(obj) ) return obj;
                }
                if( member_array(base_name(inv[i]),treasure) == -1 ) continue;
                return inv[i];
        }
        return 0;
}

void back_home()
{
        delete("is_have_target");
        remove_call_out("check_env");
        if( !mapp(environment()->query("exits")) ) {
                message_vision("$N急急忙忙离开了。\n",this_object());
                move(query("startroom"));
        }
        random_move();
        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move() :),
        }) );
}

int check_inv(object who, string obid, string obfile)
{
        object obj;
        obj = present(obid,this_object());
        if( objectp(obj) && base_name(obj) == obfile ) {
                if(objectp(present(obid,this_object()))) return 1;
        }
        obj = present(obid,environment());
        if( objectp(obj) && base_name(obj) == obfile ) {
                command("get " + obid);
                if(objectp(present(obid,this_object()))) return 1;
        }
        if( who->is_ghost() ) {
                object *inv1;
                int i, i1;
                inv1 = filter_array(all_inventory(environment()),(: $1->query("id")=="corpse" :) );
                for(i=0,i1=sizeof(inv1); i<i1; i++) {
                        obj = check_inv_in(inv1[i], obid, obfile);
                        if( !obj || base_name(obj) != obfile ) continue;
                        obj->move(this_object());
                        message_vision("$N从$n身上搜出"+obj->query("name")+"。\n");
                        return 1;
                }
        }
        if( !living(who) 
        && !who->query_temp("in_sleeping") ) {
                object *inv2;
                int i, i1;
                if( objectp(obj = present(obid,who)) ) {
                        obj->move(this_object());
                        message_vision("$N从$n身上搜出"+obj->query("name")+"。\n",this_object(),who);
                        return 1;
                }
                inv2 = all_inventory(who);
                for(i=0,i1=sizeof(inv2); i<i1; i++) {
                        obj = check_inv_in(inv2[i], obid, obfile);
                        if( !obj || base_name(obj) != obfile ) continue;
                        obj->move(this_object());
                        message_vision("$N从$n身上搜出"+obj->query("name")+"。\n",this_object(),who);
                        return 1;
                }
        }
        return 0;
}

object check_inv_in(object env, string obid, string obfile)
{
        object obj, *inv;
        int i, i1;
        if( !objectp(env) ) return 0;
        inv = all_inventory(env);
        for(i=0,i1=sizeof(inv);i<i1;i++) {
                obj = present(obid,inv[i]);
                if( !obj && inv[i]->is_container() ) 
                        obj = check_inv_in(inv[i], obid, obfile);
                if( !obj || base_name(obj) != obfile ) continue;
                return obj;
        }
        return 0;
}

void check_env(object who, object what, string obfile)
{
        object me;
        int t;
        
        if( !who ) {
                command("say");
                return back_home();
        }
        if( !what ) what = new(obfile);
        if( !what ) {
                command("say");
                return back_home();
        }

        me = this_object();
        t = who->query_temp("spoiler_mask");

        if( check_inv(who, what->query("id"), obfile) ) {
                command("halt");
                if( who->is_ghost() )
                        command("say 嘿嘿，让你交你不交，活该被打死");
                else    command("say 哼！算你识相，今天老子心情好不跟你计较了");
                set("solw_find",5);
                return back_home();
        }
        if( environment() != environment(who) ) {
                if( environment(who)->is_room() ) {
                        me->move(environment(who));
                        message_vision("$N走了过来。\n",this_object());
                } else if( environment(who)->is_char() )
                        who = environment(who);
                else {
                        command("say 哼！跑得到快，下次别在让我碰上！");
                        return back_home();
                }
        }
        if( environment() 
        && (environment()->query("no_fight") 
        || environment()->query("sleep_room")) ) {
                command("say 哼！今天算你跑得到快，下次别在让我碰上！");
                return back_home();
        }
        if( t == 0 ) {
                command("grin "+who->query("id"));
                command("say 喂！相好的，听说你有"+what->query("unit")+what->query("name"));
                command("say 大爷我想要，识相的就快点交出来吧");
                me->set_leader(who);
        } else if( t == 20 ) {
                command("say 既然不交那我就不客气了，看招吧");
        } else if( t == 45 ) {
                command("say 哼！想来你也是不见棺材不落泪的货色");
                me->kill_ob(who);
                who->fight_ob(me);
        }
        if( t > 19 && t < 44 ) {
                me->fight_ob(who);
                who->fight_ob(me);
        }
        who->add_temp("spoiler_mask",1);
        remove_call_out("check_env");
        call_out("check_env",1,who, what, obfile);
}

void do_loot(object who, object what)
{
        object *inv;
        int i,i1;
        if( !objectp(who) || !objectp(what) ) return ;
        inv = all_inventory();
        for(i=0,i1=sizeof(inv); i<i1; i++) {
                if( inv[i]->query("is_carry") ) continue;
                inv[i]->move(VOID_OB);
                destruct(inv[i]);
        }
        copy_player(who);
        inv = all_inventory();
        for(i=0,i1=sizeof(inv); i<i1; i++) {
                inv[i]->set("is_carry",1);
        }
        message_vision("$N走了出去。\n",this_object());
        move(environment(who));
        message_vision("$N走了过来。\n",this_object());
        who->set_temp("spoiler_mask",-1);
        set("is_have_target",who);
	set("chat_chance",0);
        CHANNEL_D->do_channel(this_object(),"debug",
        "Spoiler locked target! target ID:"+who->query("id")+" treasure:"+base_name(what));
        check_env(who, what , base_name(what));
}

void create()
{
        object *inv;
        int i, i1;
        seteuid(getuid());
        set_name("蒙面人", ({ random_id[random(sizeof(random_id))] }) );
        set("gender", "男性" );
        set("age", 25+random(20));
        set("long","一个蒙面人，看不出他有什么表情，不过似乎来者不善。\n");
        set("is_have_target",0);
        set("solw_find",-1);
        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/weapon/gangjia")->wear();
        inv = all_inventory();
        for(i=0,i1=sizeof(inv); i<i1; i++) {
                inv[i]->set("is_carry",1);
        }
        if( !clonep() ) return;
//        EVENT_D->add_event(this_object(),"find_target");
        call_out("find_target",Delay);
}

void die()
{
        object ob, *inv;
        int i, i1;
        inv = all_inventory();
        for(i=0,i1=sizeof(inv); i<i1; i++) {
                if( !inv[i]->query("is_carry") ) continue;
                inv[i]->move(VOID_OB);
                destruct(inv[i]);
        }
/*
        ob = new(__FILE__);
        ob->move(query("startroom"));
        ob->set("startroom",query("startroom"));
*/
        ::die();
}

void copy_player(object who)
{
        object *inv, me;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i, temp; 

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

        inv = all_inventory(who);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]->query("equipped")
                && query("weapon_prop/damage") < inv[i]->query("weapon_prop/damage") 
                && member_array(base_name(inv[i]),treasure) == -1 
                && !sscanf(base_name(inv[i]),"/d/npc/m_weapon/weapon/%*s") ) {
                        object *myinv = all_inventory();
                        for(int j=0;j<sizeof(myinv);j++) {
                                if( myinv[j]->query("weapon_prop") 
                                && myinv[j]->query("equipped") 
                                && myinv[j]->query("is_carry"))
                                        myinv[j]->move(VOID_OB);
                                        destruct(myinv[j]);
                        }
                        carry_object(base_name(inv[i]))->wield();
                        set("weapon", base_name(inv[i]));
                }
                else if( inv[i]->query("equipped") 
                && query("armor_prop/dodge") < inv[i]->query("armor_prop/dodge") 
                && member_array(base_name(inv[i]),treasure) == -1 
                && !sscanf(base_name(inv[i]),"/d/npc/m_weapon/weapon/%*s") ) {
                        object *myinv = all_inventory();
                        for(int j=0;j<sizeof(myinv);j++) {
                                if( myinv[j]->query("armor_prop") 
                                && myinv[j]->query("equipped")
                                && myinv[j]->query("is_carry"))
                                        myinv[j]->move(VOID_OB);
                                        destruct(myinv[j]);
                        }
                        carry_object(base_name(inv[i]))->wear();
                        set("armor", base_name(inv[i]));
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
        set("jiali",     query_skill("force")/3 );
//        set("jiali",     (who->query("jiali")>0)?who->query("jiali"):query_skill("force")/2 );$
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

int return_home(object home)
{
        return 0;
}

void init()
{
        if(  is_fighting() || is_killing() 
        || objectp(query("is_have_target"))
        || random(10) < 6 ) return;
        random_move();
}

