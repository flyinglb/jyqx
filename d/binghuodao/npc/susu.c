// YinTianZheng.c
// pal 1997.05.09

#include "ansi.h"

int do_killing(object ob);
inherit NPC;
inherit F_MASTER;
int ask_me();

void create()
{
    set_name("������", ({"yin susu","susu", }));
        set("long",
        "����һλ���������긾�ˣ���һ���÷���\n"
        );
                                                          
        set("gender", "Ů��");
        set("attitude", "peaceful");

        set("age", 27);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 150);
        set("combat_exp", 900000);
        set("score", 1000000);

        set_skill("force", 180);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("claw", 200);
        set_skill("literate", 100);
        set_skill("jiuyang-shengong", 180);
        set_skill("xiaoyaoyou", 120);
        set_skill("longzhua-gong", 250);


        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("claw", "longzhua-gong");
        map_skill("parry", "longzhua-gong");
        prepare_skill("claw","longzhua-gong");
        set("chat_chance", 500);
        set("chat_msg", ({
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
        }) );


        set("chat_chance_combat", 10);

        setup();

carry_object("/d/binghuodao/npc/obj/skin")->wear();
}

