// qqren.c 上官剑南

inherit NPC;
int ask_qiubai();
inherit F_MASTER;

void create()
{
    set_name("上官剑南", ({ "shangguan jiannan", "shang", "shangguan", "jiannan"}));
    set("nickname", "铁掌水上漂");
	set("long", 
        "这位上官帮主乃是一位侠义之士，铁掌帮自他接任后，力加整顿，多行侠\n"
        "义之事，不过数年声势大振，在江湖上侵寻已可以与北方的丐帮分庭抗礼了。只是后来忽\n"
        "然消声匿迹，不知所踪了。\n");
	set("gender", "男性");
	set("age", 80);
    set("attitude", "peaceful");
	set("shen_type", 1);
        set("str", 45);
	set("int", 40);
	set("con", 48);
        set("dex", 44);
	
	set("max_qi", 6000);
	set("max_jing", 6000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 200);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("force", 250);
	set_skill("guiyuan-tunafa", 250);
	set_skill("dodge", 200);
	set_skill("shuishangpiao", 250);
	set_skill("strike", 250);
	set_skill("tiezhang-zhangfa", 300);
	set_skill("parry", 200);
	set_skill("literate", 100);
	set_skill("tiexue-hammer",250);
	set_skill("duanyun-fu", 250);
		
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

    create_family("铁掌帮", 13, "帮主");


	setup();
	carry_object(__DIR__"obj/black-cloth")->wear();
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") < 50000) {
                command("hehe");
                command("say 我上官剑南可不收心地不纯的人做徒弟。");
                return;
        }
                command("say 好吧，我就收下你了。希望你苦练铁掌神功，将之发扬光大。");
                command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

