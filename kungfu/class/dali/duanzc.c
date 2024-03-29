// duanzc.c 段正淳

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("段正淳", ({ "duan zhengchun", "duan" }));
	set("title",  "大理镇南王" );
	set("long", "他就是大理国的镇南王，当今皇太弟，是有名的爱情圣手。\n");
	set("gender", "男性");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);
	
	set("max_qi", 2200);
	set("max_jing", 600);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 300000);

        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("cuff", 140);
        set_skill("strike", 150);
        set_skill("sword", 150);
        set_skill("staff", 150);
        set_skill("finger", 120);
	set_skill("kurong-changong", 150);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 130);
        set_skill("wuluo-zhang", 150);
        set_skill("duanjia-sword", 150);
        set_skill("sun-finger", 100);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);

	create_family("大理段家",18,"镇南王");
}

void attempt_apprentice(object ob)
{
        string sta = ob->query("dali_family_status") ;
	if( !stringp(sta) ) {
	        command("say 你是何人，如此大胆，假冒我府中厮仆！");
	        return ;
	}
	if ((int)ob->query_skill("kurong-changong",1) < 100 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧。");
		return;
	}
	if ((int)ob->query("shen") < 10000  ) {
		command("say 我大理段氏向来行侠仗义，您请回吧！");
		return;
	}
        command("say 很好，既然入我门来就得终身为奴供我驱使。");
	command("recruit " + ob->query("id"));
}
