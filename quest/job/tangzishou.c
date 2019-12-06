#include <ansi.h>

inherit NPC;

void create()
{
        
        set_name("趟子手", ({ "tangzi shou","tangzi"}));
        set("gender", "男性");
        set("age", random(10) + 25);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "镖局的趟子手。\n");
        set("combat_exp", 1080000); 
        set("attitude", "friendly");
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("blade", 100);
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 30);
        
        setup();

        carry_object(__DIR__"obj/blade")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        
        call_out("go_back", 60);
}

int go_back()
{
        object ob = this_object();
        
//        if(!objectp(present(me, environment(ob))))
//        {
                destruct(ob);
                remove_call_out("go_back");
                message_vision("$N急急忙忙离开了。\n", ob);
                return 1;
//        }
//        remove_call_out("do_back");
//        call_out("do_back", 30, me);
//        remove_call_out("go_back");
//        call_out("go_back", 1, me);
        return 0;

}
