// kong.c 静空师太
// Modified By That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_join();

void create()
{
        set_name("静空师太", ({ "jingkong shitai","jingkong","shitai"}));
        set("long",
        "她是峨嵋派三师姐，一位中年出家道姑，道冠高拢，慈眉善目。\n");
        set("gender", "女性");
        set("age", 45);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 10000);
        set("class", "bonze");
        set("inquiry",([
                "剃度"  : (: ask_for_join :),
                "出家"  : (: ask_for_join :),
                "还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
        ]));

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

        set("combat_exp", 250000);
        set("score", 1000);
        set_skill("persuading", 80);
        set_skill("force", 100);
        set_skill("throwing", 80);
        set_skill("dodge", 90);
        set_skill("finger", 90);
        set_skill("parry", 80);
        set_skill("strike", 100);
        set_skill("blade", 90);
        set_skill("literate", 90);
        set_skill("mahayana", 100);
        set_skill("jinding-zhang", 90);
        set_skill("tiangang-zhi", 95);
        set_skill("yanxing-dao", 80);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 100);
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
void init()
{
        add_action("do_kneel", "kneel");
}
void attempt_apprentice(object ob)
{
   if( (string)ob->query("class")!="bonze" )
   {
      command ("say 阿弥陀佛！贫尼不收弟子。\n");
      command ("say 你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。\n");
      return;
   }

   if( (string)ob->query("gender") != "女性" )
   {
      command ("say 阿弥陀佛！贫尼不收男弟子。施主若想学艺可去找我俗家师妹。");
      return;
   }
   if ((int)ob->query("shen") < 100)
   {
      command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
      return;
   }
   if ((int)ob->query_skill("mahayana",1) <50)
   {
      command("say 你大乘佛法的修为还要提高些。");
      return;
   }
   command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
   command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
   command("recruit " + ob->query("id"));
}
#include "tobebonze.h"
