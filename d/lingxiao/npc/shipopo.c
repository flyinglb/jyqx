//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void consider();
string ask_book();
void create()
{
        set_name("ʷ����",({"shi popo","popo"}));
        set("gender", "Ů��");
        set("age", 50);
        set("long", "����ѩɽ�������˰����ڵ����ӣ���˵���������Եò��ϣ�\n"
        "����ʮ��ǰ���𡰽���һ֦����ʷС������������ȴ�����˲�֪��\n");
        set("attitude", "friendly"); 

        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("qi", 2000);
        set("max_qi", 2000);
        set("jiali", 50);

        set("combat_exp", 2000000);
        set("inquiry", ([
                "���ڵ���":(:ask_book:),
        ]) );
        set("shen_type", 0);
        set("score", 50000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) ); 
        create_family("������", 5, "����");
        set_skill("force", 150);
        set_skill("dodge", 200);
        set_skill("blade", 200);
        set_skill("parry", 180);
        set_skill("unarmed", 180);
        set_skill("jinwu-blade", 200);
        set_skill("snowstep", 200); 
        set_skill("bingxue-xinfa", 150); 
        set_skill("snow-zhang",180);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 35);
        set("count", 1);


        map_skill("blade", "jinwu-blade"); 
        map_skill("force", "bingxue-xinfa"); 
        map_skill("unarmed", "snow-zhang");
        map_skill("parry", "jinwu-blade");
        map_skill("dodge", "snowstep");

        setup();

        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/money/gold");
}

string ask_book()
{
        object me,ob;
        ob=this_player(); 
        
        if(ob->query("family/master_id")=="bai wanjian")
        {
                if (query("count") == 1) {
                command("say �����򽣵ĵ�����?�Ǿ͸���ɡ�");
                message_vision(HIG"ʷ�����ͳ�һ��С����,����$N \n\n"NOR,ob);
                me=new("/d/lingxiao/obj/jinwu-book");
                me->move(ob);
                add("count", -1);
                return "��úö��������Ϲ�Ľ����ö��ˡ�\n";
                }
                else return"���������������Ѿ����������ˡ�\n";
        }
        if(ob->query("family/master_id")=="bai zizai")
        {
                if (query("count") == 1) {
                command("say �����Ϲ�ĵ�����?�Ǿ͸���ɡ�");
                message_vision(HIG"ʷ�����ͳ�һ��С����,����$N \n\n"NOR,ob);
                me=new("/d/lingxiao/obj/jinwu-book");
                me->move(ob);
                add("count", -1);
                return "��úö��������Ϲ�Ľ����ö��ˡ�\n";
                }
                else return "���������������Ѿ����������ˡ�\n";
        }

        command("say �߿�����Ȼ��̫��Ҫ�����ˣ�");
        message_vision(HIG"ʷ���ź���һ��������$N \n\n"NOR,ob);

        return "�����뿪��������,ȴҲ�����Ҵ����书\n";
}

int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
//        if ( myfam["family_name"] == "������") return 1 ;
        if ((int)ob->query_temp("tmark/shi") == 1 )
        message_vision("ʷ���ź���һ������$N˵����������첻���ٽ��ˣ����´������ɡ�\n", ob);
        if (!(int)ob->query_temp("tmark/shi"))
                return 0; 
        ob->add_temp("tmark/shi", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        
        if ( (string) ob->query("id") =="jinwu-staff" ) {
                if (!(int)who->query_temp("tmark/shi")) who->set_temp("tmark/shi", 0);
                message_vision("ʷ���Žӹ������ȣ����Ǻǡ�Ц����������������˵����\n"
                               "�ã��ã��ã��ѵ�����ҹ���Ů���£��治���ðɣ�\n"
                               "������������пգ��ͽ���һ�Ṥ��ɡ�\n", who);
                who->add_temp("tmark/shi", 900);
                return 1;
        }
        return 0;
}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say ����������,һ��ȥ�ɣ�");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 80 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
                return;
    } 
    if ((int)ob->query("shen") < 0 ) {
         command("say �������ˣ��ٲ����������������㡣"); 
                return;
    } 
    if ((int)ob->query("max_neili") < 800 ) {
         command("say ���������㣬��ȥ�򰾴������ɡ�"); 
                return;
    }
    if ((int)ob->query_skill("xueshan-sword",1) < 100 ) { 
        command("say ��ı��Ž���̫����,����������ԭ����ʦ����߰�!"); 
                return;
    }
    if ((int)ob->query_skill("sword",1) < 100 ) {  
        command("say ��Ļ�������̫����,��������߻�������!"); 
                return; 
    }
    command("say �ܺã��ܺ�,���������Ϊͽ�ɡ�");
    command("recruit " + ob->query("id"));
} 

