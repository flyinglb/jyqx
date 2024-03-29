// qingyun.c
// edward.2000.3

inherit NPC;

#include <ansi.h>

void create()
{
        set_name(HIC"青云"NOR, ({ "qingyun", "shizhe" }));
        set("long", 
                "他是掌门人的得意门生，一个十分厉害的神秘人物。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);
        set("str", 35);
        set("int", 28);
        set("con", 30);
        set("dex", 28);
        
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("combat_exp", 200000);
        set("score", 50000);

        set_skill("blade",100);
        set_skill("ruyi-dao",100);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("lingboweibu", 100);
        set_skill("beiming-shengong",100);
        set_skill("liuyang-zhang", 100);

        map_skill("unarmed", "liuyang-zhang");
        map_skill("dodge", "lingboweibu");
        map_skill("force", "beiming-shengong");
        map_skill("blade", "ruyi-dao");

        create_family("逍遥派", 2, "弟子");
        set("title",HIY"逍遥派护法使者"NOR);
        set("nickname",HIR"天使之侣"NOR);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/blade")->wield();

}

void init()
{
        object ob;

        ::init();

        ob = this_player();

	if( !interactive(ob) )
		return;
        if( ob->query("family") && ob->query("family")["master_name"]=="逍遥子") {
                command("smile");
                command("say 师弟辛苦啦，快去见师父吧，他惦记着你呢。");
        }
	else {
                command("hehe");
                command("say 你好大的胆子，本派的密室也敢闯进来 ？！\n");
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        }
}

