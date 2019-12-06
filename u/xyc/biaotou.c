//biaotou.c 总镖头
inherit NPC;

#include <ansi.h>
 
int yunbiao();

void create()
{
        set_name("总镖头", ({ "biaotou"}));
        set("gender", "男性");
        set("age", 56);
        set("long", "镖局的总镖头,似乎很有本事!。\n");
        
        set("combat_exp", 500000);
        set("shen_type", 1);

        set("chat_chance",2);
        set("chat_msg", ({
                "总镖头说道,镖局正需要帮手。\n",
                  "总镖头说道,要是有些能干的人帮忙运镖就好了......\n",
                  "总镖头说道,宗师太懒了，做东东只做一半就不做了！....\n",
        }) );
        set("attitude", "peaceful");
        
        set("inquiry", ([
                  "运镖" : "笨蛋！我还没做好呢！\n",
                  "护镖" : "笨蛋！我还没做好呢！\n",
//                  "运镖" : (: yunbiao :),
//                  "护镖" : (: yunbiao :),
        ]) );
        
        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        set_temp("apply/attack", 500);
        set_temp("apply/defense", 500);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",10);
}

