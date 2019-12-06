#include <ansi.h>

inherit NPC;

void create()
{
        set_name("ʱ����",({"shi wannian","shi",}));
        set("gender", "����");
        set("age", 20);
        set("long", 
               "���������ǵ���������ʱ���꣬�ڴ�����������\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("qi", 1500);
        set("max_qi", 1500);

        set("combat_exp", 250000); 
        set("shen_type", 0);
        set("score", 20000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
       "ʱ����޺�˵�����Ϸ��Ӳ�֪������ô�ˣ����Լ���������Ū�����ϳ�����\n", 
       "ʱ����ѽ�һ������Ȼ�������������⣬˭��������Ϸ��ӷų�����\n", 
        }) );
        set_skill("unarmed", 100);
        set_skill("sword", 120);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("literate", 80);

        set_skill("xueshan-sword", 120);
        set_skill("bingxue-xinfa", 100);
        set_skill("snow-zhang", 100);
        set_skill("snowstep", 120);


        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("������", 6, "����");
        setup();

        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
} 
void init()
{ 
        object ob;
        ::init();

        ob = this_player();  
      if(ob->query("family/family_name") !="������")
        {
                command("heng");
                command("say ���Ȼ�Ҵ��뱾�ɽ��أ������ɣ�\n");
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        }
        else if(ob->query("family")["master_name"]=="������")
        {
                command("say ʦ������ˣ���ȥ��ʦ��ɣ�����С�ĵ㡭��û׼���ַ����ˡ�");
        } 
        else if(ob->query("family")["master_name"]=="����")
        {
                command("say ���ǰ�ʦ��ĵ��Ӱɣ����ȥ������ү�Ӱɣ����Ĳ�Խ��Խ����������");
        }
}

