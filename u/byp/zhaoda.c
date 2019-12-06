// zhaoda.c �Դ�

inherit NPC;
inherit F_UNIQUE;

int ask_job();
void do_dest(object ob);

void create()
{
        set_name("�Դ�", ({ "zhao da", "zhao" }));
        set("long", "����Լ��ʮ���꣬�����ܸɣ�Ц�����ĺͰ����ס���ȴ������������һ�\n");
        set("gender", "����");
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

        create_family("���͵�", 2, "����");

        set("inquiry",([
                "job" : (:ask_job:),
                "����" : (:ask_job:),
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
                tell_object(me,name() +"��Ц�Ŷ���˵�������㻹�ǻؼҶ��������ڳ����ɡ���\n");
                return 1;
        }
        
        if(me->query("zhao_job/bonus") > 0) {
                str = me->query("zhao_job/name");
                tell_object(me,name() +"��Ц�Ŷ���˵�������ϴ�ɱ"+str+"���º����㻹û����ɡ���\n");
                return 1;
        }
        
        if(me->query("qian_job/bonus") > 0
        || me->query("quest")) {
                tell_object(me,name() +"��Ц�Ŷ���˵����������ȥæ���Լ����°ɡ���\n");
                return 1;
        }
        all = livings();
        for(i=0; i<sizeof(all); i++) {
                if( all[i]->query("family/family_name") == "���͵�" ) continue;
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
                tell_object(me,name() +"����˵����������ûʲô�¿��Ը���������\n");
                return 1;
        }
        
        me->set("zhao_job/name", who->name());
        
        if(who_exp > me_exp)
                me->set("zhao_job/bonus", 2);
        else 
                me->set("zhao_job/bonus", 1);
        tell_object(me,name() +"����˵�������ðɣ���ȥ���Ұ�"+who->name()+"��ɱ�ˡ���\n");
        return 1;
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id")) {
                if( undefinedp(who->query("zhao_job")) ) {
                        tell_object(who, name()+"Ц�������ҿɾͲ������ˡ�\n");
                } else if ( ob->value() < 5000) {
                        tell_object(who, name()+"�ߵ�һ��˵�������Ǯ�ɲ������ǿ����ģ�\n");
                } else {
                        tell_object(who, name()+"Ц�����Ǻã������������������ڡ����ֲ�ʹ�����Ұɣ�\n");
                        who->delete("zhao_job");

                }
                call_out("do_dest", 1, ob);
                return 1;
        } else {
                tell_object(who, name()+"˵�����ⲻ������Ҫ�ġ�\n");
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
