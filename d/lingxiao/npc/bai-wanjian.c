//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

inherit F_MASTER;
void create()
{
        set_name("����",({"bai wanjian","bai"}));
        set("nickname", HIC"��������"NOR);
        set("gender", "����");
        set("age", 30);
        set("long", 
               "������ѩɽ���������������������ڵĳ��ӣ���\n"
                "��ʦ�ֵܾ��ԡ��������У������־�Ȼ�е�����,\n"
                "�������֮��.�������������,�롮�������������\n"
                "��ϳơ�ѩɽ˫�ܡ���\n");
        set("attitude", "peaceful");

        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("per", 30);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("qi", 2000);
        set("max_qi", 2000);
        set("jiali", 80);

        set("combat_exp", 1500000);
        set("score", 50000);
        set("inquiry", ([
            "������"   : "��ү�ӵ�̨������е���!��",
            "��ү��"   : "����ݼ���ү���𣿵����չ����,����ҳ�ʦ��Ҫ������,���ܼ�������",
            "����"   : 
     "����ݼ���ү���𣿵����չ����,����ҳ�ʦ��Ҫ������,���ܼ�������",
              "����"   : "���������������ر�,ֻ��ƾ��,���ܽ��������",
        ]));
        set("shen_type", 1);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("force", 150);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("literate", 120);

        set_skill("xueshan-sword", 150);
        set_skill("bingxue-xinfa", 150);
        set_skill("snow-zhang", 100);
        set_skill("snowstep", 120);

        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("������", 6, "����");
        setup();

        
        carry_object("/clone/money/gold.c");
        carry_object("/d/lingxiao/obj/baihongjian.c")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 28) {
        command("say ����������,���ܸ���ѧ����");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 60 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
                return;
    } 
    if ((int)ob->query_skill("xueshan-sword",1) < 80 ) { 
        command("say ��ı��Ž���̫����,����������ԭ����ʦ����߰�!"); 
                return;
        }
    if ((int)ob->query_skill("sword",1) < 80 ) {  
        command("say ��Ļ�������̫����,��������߻�������!"); 
                return; 
    }
    if ((int)ob->query("shen") < 20000 ) {
         command("say ѧ��������������������?"); 
                return;
    } 

    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", "�����ǵ��ߴ�����"); 
}

