// yangguo.c ���

inherit NPC;

string ask_xuantiesword();

inherit F_MASTER;
void create()
{
        set_name("���", ({ "yang guo", "yang" }));
        set("nickname", HIG "������" NOR);
        set("gender", "����");
        set("age", 30);
        set("per",30);
        set("con",30);
        set("str", 30);
        set("class","gumu");
        set("dex", 30);
        set("long", "����һλ�ߴ�����ӣ���ò���㡣\n"+
                "һֻ����տ���Ҳ�����Ƕ���һ�ۣ�������ˣ�\n"+
                "��Ȼ�ڲ�ס�����˵ķ�ɡ�����Ը����д�(qiecuo)\n");
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
                "С��Ů" : "�����ҵĹùá�\n",
                "��ʦ": "��������������书��Ȼ���پ����ղ����㡣��������(accept test)��\n",
                "���ӽ�": "�ܿ�ϧ,���ӽ��Ѿ������������ˡ�\n",
                "������": (: ask_xuantiesword :),
                "�д�":"����Ը��ҽ����д�(qiecuo)\n",
        ]) );
        create_family("��Ĺ��", 4, "����");
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
        ob->set("title",HIW"����մ�����"NOR);
        return;
}

int recognize_apprentice(object ob)
{
       if(!ob->query("marks/win_guo_time"))
               return 0;
       if((time() - ob->query("marks/win_guo_time") ) > 900) {
                say("���˵�����������ѧ�˲����ˣ�������������(qiecuo)һ�°ɣ�\n");
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
                command("say ��Ĺ����治���������д�����\n");
                return 1;
        }
        //if who have qiecuo,and the time have beyond 2 hours,then he can qiecuo
        if(time() - me->query("marks/qiecuo_last_time") < 72000) {
                say("���˵�����㲻��ǰ������ң��������ٱȰɣ�\n");

                return 1;
        }
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
        say("\n�������һ�У�������\n");
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
        say("\n����������У�������\n");
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
        say("\n����������У�������\n");
        dkee=target->query("qi");
        if(!(dkee<skee)) {
                say("���˵�����������书���У���������Щ�����ɣ�\n");
                me->set("marks/qiecuo_last_time",time());
        } else {
                say("\n���˵������Ĺ����治���ӽ��Ժ����Ǿ��໥ѧϰ�ɣ�\n");
                me->set("marks/win_guo_time",time());
        }
        return 1;
}
int do_accept(string arg)
{
             //mapping guild;
        object who = this_player();
        
        if( arg != "test" ) return 0;
        
        if((string)who->query("family/family_name") != "��Ĺ��") {
                command("say ����ȥ���ҹùðɡ�\n");
                return 1;
        }
        if(who->query("shen")>50000) {
                command("say �������������������Щ��ν����������򽻵���\n");
                return 1;
        }
        if(who->query("shen")<-50000) {
                command("say �����������ʹ��������Ща���������ҹ���\n");
                return 1;
        }
        if(who->query("str")<25) {
                command("say �����̫�ѧ�����ҵ��书��\n");
                return 1;
        }
        if(who->query("combat_exp")<800000) {
                command("say �㵱����˭������Ҳ��ѧ���书����\n");
                return 1;
        } 
        if(who->query("family/master_id") == query("id")) {
                say("\n����������ͷ�����㽫���ض���һ������֮���ˣ�\n");
                return 1;
        }
        
        say("\n������˵�ͷ��˵�����ܺã����������У����ǵ�һ��....\n\n");
        COMBAT_D->do_attack(this_object(), who, query_temp("weapon"));
        
        if( who->query("qi") < 1 ) {
                say("���̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
                who->die();
                return 1;
        }
        
        say("\n���˵�����������ǵڶ���....\n\n");
        COMBAT_D->do_attack(this_object(), who, query_temp("weapon"));
        
        if( who->query("qi") < 1 ) {
                say("������ߡ���һ����˵��������������಻�����ļһ�....\n");
                who->die();     
                return 1;
        }
        
        say("\n���˵��������������....\n\n");
        COMBAT_D->do_attack(this_object(), who, query_temp("weapon"));
        
        if( (int)who->query("qi") < 1 ) {
                say("���̾������ϧ��������Ե ....\n");
                who->die();
                return 1;
        }
                     
        say("\n���������Ц��˵������������ٵ�һ������֮�ţ�\n\n");
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
                if( (string)name == "С��Ů") {
                        message_vision("$N��Цһ��������ɱ�ҹùã��ҿ�����̫���ˡ�\n", this_object());
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
        me->set_temp("tmark/��",1);
        return("����������ڽ�ڣ��?\n");
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

