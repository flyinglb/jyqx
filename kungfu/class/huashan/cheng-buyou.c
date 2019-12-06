// cheng-buyou.c  �ɲ���
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("�ɲ���", ({ "cheng buyou", "cheng" }) );
        set("gender", "����");
        set("class", "swordsman");
        set("title", "��ɽ���ڵ�ʮ��������");
        set("age", 41);
        set("long",
                "һ���׾���Ƥ�İ��ӣ���Ҳ����С������\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 4000);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);

        set("combat_exp", 1000000);
        set("shen", -200000);
        set("apprentice_available", 3);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.feilong" :),
                (: exert_function, "powerup" :),
        }) );

        set_skill("unarmed", 80);
        set_skill("sword", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("literate", 100);
        set_skill("huashan-sword", 150);
        set_skill("huashan-neigong", 150);
        set_skill("huashan-ken", 80);
        set_skill("huashan-zhangfa", 80);
        set_skill("huashan-shenfa", 120);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "huashan-neigong");
        map_skill("unarmed", "huashan-zhangfa");
        map_skill("dodge", "huashan-shenfa");

        create_family("��ɽ�ɽ���", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if(ob->query("family/master_id") != "yue buqun")
              say ("�ɲ���˵����λ"+RANK_D->query_respect(ob) + "����Ͷ�ҽ��ڰɡ�\n");
        else
        {
              message_vision("�ɲ���һ��$N�ʹ�ŭ����������α���ӵ�ͽ���ˡ�\n", ob);
              this_object()->kill_ob(ob);
        }
        return;
}

void attempt_apprentice(object ob)
{
        command("say �Ϸ�Ӳ���ͽ�������ҷ�ʦ�ֺ��ˡ�");
}

