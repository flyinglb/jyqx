//yue-wife.c    changed by cocacola on 2.19.1997 Just for adding Chushi
// ������
inherit NPC;
inherit F_MASTER;
/*
mixed out_master(mixed arg);
mixed out_master(mixed arg)
{
   object me;
   me = this_player();
   if( (string)me->query("family/family_name")!="��ɽ��")
   {
         tell_object(me,"�������ɻ�ض���˵:�Һ������ļ������Ƶ�!\n");
         return 1;
   }
   if(me->query("gender")!="Ů��")
   {
         tell_object(me,"��λС�ֵ�,�������ɷ��ͽ��,���ʦ��ȥ��������!\n");
         return 1;
   }
   if(me->query("combat_exp") <= 100000) 
   {
         tell_object(me,"�����˶�"+me->query("name")+"Ц��:С����,����ûѧ���Ҿ����ȥ����.\n");
         return 1;
   }
   tell_object(me,"�����˳�����һ��,��"+me->query("name")+"˵��:Ҫ���ʦ,
          �����������в���(accept test).\n");
   add_action("do_accept","accept");
   return 1;
}

int do_accept(string arg)
{
   mapping guild;

   if( arg== "test" ) 
   {
          say("\n�����˵��˵�ͷ��˵�����ܺã�С���ˡ������ǵ�һ��....\n\n");
          COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
          if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment()))
          {
               say("������̾�˿�����˵��:����һ�ж��Ų����������Բ�����....\n");
               return 1;
          }
          say("\n�����˵����ڶ���....\n\n");
          COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
          if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment())) 
          {
               say("������̾���������ӻ����ʦ,��.....\n");
               return 1;
          }
          say("\n�����˵��������п�û��ô����,���ҪС����!....\n\n");
          COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
          if( (int)this_player()->query("kee") < 0 || !present(this_player(), environment())) 
          {
               say("������̾��:��,�Ͳ�һ�����,����Ŭ����!.\n");
               return 1;
          }
          say("\n������΢Ц�ŵ�����ϲ,���ʦ��.����ʦͽһ����Ϊʦûʲô���͵� .
          \n������������԰�:��������,��������!ͽ��,�,��...���������Ϊ֪.\n\n");
          this_player()->set("betrayer",this_player()->query("betrayer")-1);
          this_player()->set("title","��ʿ");
          this_player()->set("family/family_name","��ɽ��");
          this_player()->set("family/generation",13);
          this_player()->set("family/master_name",0);
          command("chat " + this_player()->query("name")+"�����뻪ɽ���պ�һ�н���
           ��Թ���뱾���޹�.\n");
          return 1;
   }
   return 0;
}
*/
void create()
{
          set_name("������", ({ "ning", "yue wife", "ning zhongze" }) );
          set("nickname", "������");
        set("gender", "Ů��");
        set("class", "swordsman");
        set("age", 50);
        set("long",
                "������ԭ����������������������Ⱥ��ʦ�ã�Ҳ���������ӡ�\n");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 26);
        set("per", 26);
        set("int", 24);
        set("con", 30);
        set("dex", 30);

        set("neili", 4000);
        set("max_neili", 2400);
        set("jiali", 30);

        set("max_qi",2000);
        set("max_jing",1000);
        set("combat_exp", 1000000);
        set("shen", 200000);

        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
/*
        set("inquiry", ([
            "��ʦ": (: out_master :),
        ]) );
*/
        set_skill("unarmed", 80);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);

        set_skill("huashan-sword", 100);
        set_skill("yunu-sword", 100);
        set_skill("zixia-shengong", 100);
        set_skill("huashan-ken", 80);
        set_skill("feiyan-huixiang", 100);
        set_skill("zhengqijue", 100);

        map_skill("sword", "yunu-sword");
        map_skill("parry", "yunu-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say �������Ӵ��");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" ){
                 command("say ��λ"+RANK_D->query_respect(ob)+
"�㻹�����ҷ��ȥ��.");
        }else {
        command("say ΢Ц�����ã��ã�ֻҪ������ѧ�����ձ��гɾ͡�");
        command("recruit " + ob->query("id") );
   }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
        add("apprentice_availavble", -1);
}
void reset()
{
//        delete_temp("learned");
        set("apprentice_available", 3);
}
