//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("燕万鹏",({"yan wanpeng","yan"}));
        set("gender", "男性");
        set("age", 20);
        set("long", 
               "他是凌霄城第六代弟子燕万鹏,第六代弟子中,为人数他最\n"
                "为梗直,素有铁面之称,所以在此镇狱。\n");
        set("attitude", "peaceful");

        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("qi", 2500);
        set("max_qi", 2500);
        set("jiali", 80);

        set("combat_exp", 500000);
        set("shen_type", 1);
        set("score", 50000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 80);

        set_skill("xueshan-sword", 100);
        set_skill("bingxue-xinfa", 100);
        set_skill("snow-zhang", 100);
        set_skill("snowstep", 100);

        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("凌霄城", 6, "弟子");
        setup();

        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int accept_object(object me, object ob)
{
   object nowords;

     if ((string)ob->query("name")!=HIW"寒玉牌"NOR) {
            command("say 你给我这个干什么！你想贿赂我吗？");
            return 1;
        }
        else {
            command("say 师弟请下去吧，老爷子在下面。\n");
                me->move("/d/lingxiao/laolang");
            return 1;
        }
}

