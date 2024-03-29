// XieXun.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void destroy(object ob)
{
        if(!ob) return;
        ob->move(VOID_OB);
        destruct(ob);
}

void create()
{
	set_name("谢逊", ({"xie xun", "xie", "xun", }));
	set("long",
        "他是一位身材魁伟异常的的老者，身穿一件白布长袍。\n"
        "他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。\n"
	);

	set("title",HIG "明教" HIY "金毛狮王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 63);
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);

	set("combat_exp", 900000);
	set("score", 800000);

    	set_skill("force", 160);
	set_skill("dodge", 140);
	set_skill("sword", 140);
	set_skill("blade", 140);
	set_skill("parry", 140);
        set_skill("unarmed", 200);
	set_skill("blade", 140);
	set_skill("jinwu-daofa", 140);
	set_skill("jiuyang-shengong", 160);
	set_skill("lingxu-bu", 140);
    	set_skill("damo-jian", 140);
    	set_skill("qishang-quan", 200);
    	set_skill("hunyuan-zhang", 150);
    	set_skill("literate", 100);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
        map_skill("unarmed", "qishang-quan");
    	map_skill("parry", "hunyuan-zhang");
    	map_skill("sword", "damo-jian");
	map_skill("blade", "jinwu-daofa");

        prepare_skill("unarmed","qishang-quan");

	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
	}) );
	create_family("明教",34, "法王");
	setup();
    	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if (interactive(this_player()) && this_player()->query_temp("fighting"))
	{
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}       
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

int accept_object(object who, object ob)
{
	object qkbook;
        if ((string)ob->query("id")=="yi xin") {
            if(!query("qk_trigger")) {
                call_out("destroy",1,ob);
		qkbook = new("/clone/book/qiankun_book");
		say("谢逊说道：谢谢你终于让我知道了阳教主的下落，我无以酬谢，这张羊皮就聊表谢意吧。\n"
"谢逊把" + qkbook->query("name") + "交给了" + who->query("name") + "。\n");
		qkbook->move(who);
		command("rumor "+who->query("name")+"拿到乾坤大挪移心法了。\n");
                set("qk_trigger", 1);
            }
	}
	return 1;
}
#include "fawang.h"
