// ling.c 赵灵珠

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("赵灵珠", ({ "zhao lingzhu","zhao","lingzhu"}));
        set("long",
                "她是峨嵋派的第四代俗家弟子。\n");
        set("gender", "女性");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "fighter");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 150000);
        set("score", 1000);
        set_skill("throwing", 30);
        set_skill("persuading", 50);
        set_skill("force", 70);
        set_skill("dodge", 80);
        set_skill("finger", 60);
        set_skill("parry", 80);
        set_skill("strike", 60);
        set_skill("blade", 90);
        set_skill("jinding-zhang", 60);
        set_skill("tiangang-zhi", 60);
        set_skill("yanxing-dao", 90);
        set_skill("zhutian-bu", 80);
        set_skill("linji-zhuang", 70);

        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("blade","yanxing-dao");
        map_skill("parry","yanxing-dao");
        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("combat_exp") > 10000) {
                command("say 我峨嵋注重清修，对弟子要求能忍受寂寞。");
                command("say 在江湖阅历方面，" + RANK_D->query_respect(ob) +
                        "经历丰富，是否能在峨嵋修道？");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
