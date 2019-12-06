///ouyangfeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int ask_job();
void create()
{
	set_name("欧阳锋", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "他是白驼山庄主，号称“西毒”的欧阳锋。\n"
		   +"由于习练「九阴真经」走火入魔，已变得精\n"
		   +"神错乱，整日披头散发。\n");
	set("title", "白驼山庄主");
	set("gender", "男性");
	set("age", 53);
	set("nickname", HIR "西毒" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");

        set("inquiry", ([
                "job"      :(:ask_job:),
        ]) );

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 900);
	set("max_jing", 900);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set("combat_exp", 1500000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",170);
	set_skill("training",150);
	set_skill("staff", 170);
	set_skill("hamagong", 200);
	set_skill("chanchu-bufa", 170);
	set_skill("shexing-diaoshou", 170);
	set_skill("lingshe-zhangfa", 170);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	create_family("白驼山派",1, "开山祖师");
        set("chat_chance",2);
        set("chat_msg",({
         "欧阳锋自言自语道：何日白驼山派才能重霸江湖呢…\n",
         "欧阳锋道：我儿欧阳克必能够重振白驼山派雄风！\n",
         "欧阳锋道：江湖险恶，困难重重哪！\n",
        }));
	setup();
	carry_object("/d/baituo/obj/shezhang")->wield();
        carry_object("/d/baituo/obj/baipao")->wear();
	carry_object("/clone/book/staff_book2");
	add_money("silver",50);
}

void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<100000)
        {
          message_vision("欧阳锋对$N笑道：你的经验太低了,我还不能收你！\n",ob);
	return ;
         }
   message_vision("欧阳锋拍拍$N的头，微微点了点头。\n",ob);
   command("recruit " + ob->query("id"));
   return;
}

int ask_job()
{
        object who = this_player();
        int pot = (int)(who->query("potential")) - (int)(who->query("learned_points"));

        if (who->query("family/family_name")!="白驼山派"){
        write(name()+"哼道：你不是白驼山弟子！这里不需要外人帮手！\n");
                return 1;
        }
        if(who->query_temp("job_btshan")) {
        write(name()+"对你说道：你不是还有事做么？先去干完你的活。\n");
        return 1;
        }
        if(pot >= who->query_int() * 30 ) {
        write(name()+"对你说道：你先去忙完你自己的事情吧！\n");
        return 1;
        }
        if(who->query("combat_exp") > 500000 ) {
        write(name()+"对你说道：你的经验太高！还是让其他人来做吧！\n");
        return 1;
        }
        who->set_temp("job_btshan",1);
        message_vision(name()+"对$N说道：好吧，你去向老顾要点蛇粮吧！！\n", who);
        return 1;
}
