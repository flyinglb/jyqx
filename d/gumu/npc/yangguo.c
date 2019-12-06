// yangguo.c 杨过

inherit NPC;

string ask_xuantiesword();

inherit F_MASTER;
void create()
{
        set_name("杨过", ({ "yang guo", "yang" }));
        set("nickname", HIG "神雕大侠" NOR);
        set("gender", "男性");
        set("age", 30);
        set("per",30);
        set("con",30);
        set("str", 30);
        set("class","gumu");
        set("dex", 30);
        set("long", "他是一位高大的男子，相貌俊秀。\n"+
                "一只长袖空空如也，显是断了一臂，尽管如此，\n"+
                "仍然掩不住他迷人的风采。你可以跟他切磋(qiecuo)\n");
        set("combat_exp", 1500000);
        set("score", 10000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("finger", 100);
        set_skill("hamagong", 80);
        set_skill("yunv-jian", 200);
        set_skill("xuantie-sword", 200);
        set_skill("quanzhen-jian", 100);
        set_skill("staff", 100);
        set_skill("dagou-bang", 100);
        set_skill("tanzhi-shentong", 100);
        set_skill("parry", 200);
        set_skill("anranxiaohun-zhang",200);
        set_skill("tanzhi-shentong", 100);
        set_skill("yunv-shenfa",200);
        set_skill("yunv-xinfa",200);
        map_skill("sword", "xuantie-sword");
        map_skill("finger", "tanzhi-shentong");
        map_skill("force", "yunv-xinfa");
        map_skill("staff", "dagou-bang");
        map_skill("parry", "anranxiaohun-zhang");
        map_skill("unarmed","anranxiaohun-zhang");
        map_skill("dodge", "yunv-shenfa");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "sword.feihongrudian" :),
                     
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 240);
        set_temp("apply/damage", 200);
        set("neili", 8000); 
        set("max_neili", 8000);
        set("jiali", 100);
        set("max_qi", 6000);
        set("qi",6000);
        set("inquiry", ([
                "小龙女" : "她是我的姑姑。\n",
                "拜师": "先让我试试你的武功，然后再决定收不收你。你想试试(accept test)？\n",
                "君子剑": "很可惜,君子剑已经不在我手里了。\n",
                "玄铁剑": (: ask_xuantiesword :),
                "切磋":"你可以跟我进行切磋(qiecuo)\n",
        ]) );
        create_family("古墓派", 4, "弟子");
        setup();
        carry_object("/d/gumu/obj/qingyi")->wear();
        carry_object("/d/gumu/obj/tiesword")->wield();
}

void init()
{
        ::init();
        add_action("do_accept", "accept");
        add_action("do_qiecuo","qiecuo");
        add_action("do_killing", "kill");
}

void attempt_apprentice(object ob)
{ 
        if(!ob->query("marks/be_yangguo"))
                return;
        command("recruit " + ob->query("id") );
        ob->set("title",HIW"杨过嫡传弟子"NOR);
        return;
}

int recognize_apprentice(object ob)
{
       if(!ob->query("marks/win_guo_time"))
               return 0;
       if((time() - ob->query("marks/win_guo_time") ) > 900) {
                say("杨过说道：你从我这学了不少了，我们来再砌磋(qiecuo)一下吧！\n");
                return 0;
       }
       return 1;
}

int do_qiecuo()
{
        //mapping guild;
        int skee,dkee;
        object me,target;
             
        me=this_player();
        target=this_object();
        skee=target->query("qi");
             
        if((time()-me->query("marks/win_guo_time")) < 900) {
                command("say 你的功夫真不错，不用再切磋啦！\n");
                return 1;
        }
        //if who have qiecuo,and the time have beyond 2 hours,then he can qiecuo
        if(time() - me->query("marks/qiecuo_last_time") < 72000) {
                say("杨过说道：你不久前才输给我！过两天再比吧！\n");

                return 1;
        }
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
        say("\n杨过道：一招．．．．\n");
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
        say("\n杨过道：二招．．．．\n");
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
        say("\n杨过道：三招．．．．\n");
        dkee=target->query("qi");
        if(!(dkee<skee)) {
                say("杨过说道：看来你武功不行，等你练好些再来吧！\n");
                me->set("marks/qiecuo_last_time",time());
        } else {
                say("\n杨过说道：你的功夫真不错，从今以后我们就相互学习吧！\n");
                me->set("marks/win_guo_time",time());
        }
        return 1;
}
int do_accept(string arg)
{
             //mapping guild;
        object who = this_player();
        
        if( arg != "test" ) return 0;
        
        if((string)who->query("family/family_name") != "古墓派") {
                command("say 你先去拜我姑姑吧。\n");
                return 1;
        }
        if(who->query("shen")>50000) {
                command("say 我杨过向来不跟你们这些所谓的正派人物打交道。\n");
                return 1;
        }
        if(who->query("shen")<-50000) {
                command("say 我杨过向来最痛恨你们这些邪派人物，快给我滚！\n");
                return 1;
        }
        if(who->query("str")<25) {
                command("say 你臂力太差，学不会我的武功。\n");
                return 1;
        }
        if(who->query("combat_exp")<800000) {
                command("say 你当我是谁，连你也想学我武功？。\n");
                return 1;
        } 
        if(who->query("family/master_id") == query("id")) {
                say("\n杨过拍拍你的头道：你将来必定是一个可造之才了！\n");
                return 1;
        }
        
        say("\n杨过点了点头，说道：很好，我试你三招，这是第一招....\n\n");
        COMBAT_D->do_attack(this_object(), who, query_temp("weapon"));
        
        if( who->query("qi") < 1 ) {
                say("杨过叹了口气，说道：连第一招都撑不过，真是自不量力....\n");
                who->die();
                return 1;
        }
        
        say("\n杨过说道：不错，这是第二招....\n\n");
        COMBAT_D->do_attack(this_object(), who, query_temp("weapon"));
        
        if( who->query("qi") < 1 ) {
                say("杨过「哼」地一声，说道：便是有这许多不怕死的家伙....\n");
                who->die();     
                return 1;
        }
        
        say("\n杨过说道：第三招来了....\n\n");
        COMBAT_D->do_attack(this_object(), who, query_temp("weapon"));
        
        if( (int)who->query("qi") < 1 ) {
                say("杨过叹道：可惜，咱们无缘 ....\n");
                who->die();
                return 1;
        }
                     
        say("\n杨过哈哈大笑，说道：今日终於觅得一个可造之才！\n\n");
        who->set("marks/be_yangguo",1);
        return 1;
}

int do_killing(string arg)
{
             
        object player, victim;//, weapon;
        string name;
        player = this_player();
        
        if( !arg) return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = (string)victim->name();
                if( (string)name == "小龙女") {
                        message_vision("$N冷笑一声道：敢杀我姑姑，我看你活得太长了。\n", this_object());
                        this_object()->kill_ob(player);
                        player->kill_ob(this_object());
                        return 1;
                }
        }
        return 0;               
}

string ask_xuantiesword()
{
        object me=this_player();
        me->set_temp("tmark/玄",1);
        return("玄铁剑埋藏在剑冢中?\n");
}

void die()
{
        object *inv = all_inventory(this_object());
        
        for(int i =0;i<sizeof(inv);i++) {
                if( inv[i]->query("id") != "xuantiesword" ) continue;
                destruct(inv[i]);
        }
        return ::die();
}

