// hlj_npc.c 红莲教众

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("小三子", ({"xiao san", "xiao", "san"}));
        set("gender", "男性");
        set("nickname",HIR"红莲教众"NOR);
        set("age", 26);
        set("long", 
                "他是红莲教的一名教众，他似乎在守门。\n");
        set("attitude", "peaceful");
        
        set("str", 25);
        set("int", 17);
        set("con", 18);
        set("dex", 27);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 500);
        set("max_jing", 500);
        set("neili", 800);
        set("max_neili", 800);
        
        set("combat_exp", 15000);
         
        set_skill("force", 20);             
        set_skill("unarmed", 30);           
        set_skill("dodge", 20);             
        set_skill("parry", 30);             
        
        setup();
        
        carry_object("/clone/misc/cloth")->wear();
}
