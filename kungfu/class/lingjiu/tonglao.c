// NPC tonglao.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
#define Last_Time "/data/npc/tonglao"

string ask_me();

void create()
{
        set_name("天山童姥", ({ "tong lao", "tong", "lao" }));
        set("long",
            "她就是「灵鹫宫」的开山祖师.\n"+
            "乍一看似乎是个十七八岁的女子,可神情却是老气横秋.\n"+
            "双目如电,炯炯有神,向你瞧来时,自有一股凌人的威严.\n");
        set("title", "灵鹫宫主人");
        set("gender", "女性");
        set("age", 96);
        set("nickname", HIR "唯我独尊" NOR);
        set("shen_type",0);
        set("attitude", "peaceful");
        set("no_get", 1);

        set("str", 25);
        set("int", 35);
        set("con", 40);
        set("dex", 40);

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);

        set("combat_exp", 2500000);
        set("score", 200000);
        set_skill("force", 200);
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("hand",250);
        set_skill("strike", 250);
        set_skill("sword",150);

        set_skill("zhemei-shou",200);
        set_skill("liuyang-zhang",200);
        set_skill("tianyu-qijian",120);
        set_skill("yueying-wubu",200);
        set_skill("bahuang-gong", 250);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("strike","liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword","tianyu-qijian");

        prepare_skill("hand","zhemei-shou");
        prepare_skill("strike","liuyang-zhang");
        create_family("灵鹫宫",1, "开山祖师");

        set("inquiry", ([
                "青春无价"     : (: ask_me :),
        ]));
        set("age_count", 1);

        setup();
        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
}
string ask_me()
{
//      mapping fam; 
        object ob;
        
        if (  this_player()->query("combat_exp") < 100000
        ||    this_player()->query("age") < 40 )
        {
                command("say 你算什么东西，乳臭未干，也敢来和我说话！");
                this_object()->kill_ob(this_player());
                this_player()->kill_ob(this_object());
        }
        if( (uptime() < 48000) || (time() - atoi(read_file(Last_Time)) < 10800) )
                return "岁月金丹乃是我采无数药物制炼的，现在还没炼成。";
        if (query("age_count") < 1)
                return "岁月金丹乃是我采无数药物制炼的，现在还没炼成。";
        ob = new("/d/lingjiu/obj/age_dan");
        ob->move(this_player());
        add("age_count", -1);
        write_file(Last_Time, ""+time(), 1);
        message_vision("\n童姥微微一笑：“真正了解人生什么最重要的人太少了。”取出一粒丹药递给$N。\n\n", this_player());
        message("channel:rumor", HIM"【"+HIR+"谣言"+HIM+"】"+HIR+"某人："+this_player()->query("name")+"得到"+HIG+"岁月"+HIY+"金丹"+HIR+"了。\n"NOR, users());
        return "喏，这就是了，拿去吧！";
}

void attempt_apprentice(object ob)
{
   
        if ((string)ob->query("gender")!="女性")
        {
                command("say 你找死啊!");
                return;
        }
        if ((int)ob->query_skill("bahuang-gong", 1) < 130) 
        {
                command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
                return;
        }
        if (ob->query_con() < 30) 
        {
                command("say 本门功法极为难练,你的根骨似乎不够.");
                return;
        }
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "dancer")
        ob->set("class", "dancer");
        return;
}
void die()
{
        write_file(Last_Time, ""+time(), 1);
        ::die();
}
