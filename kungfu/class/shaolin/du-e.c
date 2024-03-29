               
inherit NPC;
inherit F_MASTER;
#define Last_Time "/data/npc/du-e"
#include <ansi.h>

string ask_me();

void create()
{
        set_name("渡厄", ({ "du e", "e" }) );
        set("title", "少林长老");
        set("gender", "男性");
        set("age", 90);
        set("long",
                "这是一个面颊深陷，瘦骨零丁的老僧，他脸色枯黄，如同一段枯木。\n");

        set("attitude", "peaceful");
        set("class", "bonze");
        set("combat_exp", 1500000);
        set("score", 200000);
        set("no_get", 1);

        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);

        set("qi", 4000);
        set("max_qi", 2000);
        set("neili", 4000);
        set("max_neili", 2000);
        set("jiali", 90);

        create_family("少林派", 35, "弟子");
        assign_apprentice("弟子", 0);

        set_skill("force", 150);
        set_skill("whip", 170);
        set_skill("parry", 180);
        set_skill("dodge", 180);

        set_skill("hunyuan-yiqi", 150);
        set_skill("riyue-bian", 190);
        set_skill("shaolin-shenfa", 180);

        map_skill("force", "hunyuan-yiqi");
        map_skill("whip",  "riyue-bian");
        map_skill("parry", "riyue-bian");
        map_skill("dodge", "shaolin-shenfa");

        set_skill("blade", 150);
        set_skill("claw", 150);
        set_skill("club", 150);
        set_skill("cuff", 150);
        set_skill("finger", 150);
        set_skill("hand", 150);
        set_skill("staff", 150);
        set_skill("strike", 150);
        set_skill("sword", 150);

        set_skill("banruo-zhang", 150);
        set_skill("cibei-dao", 150);
        set_skill("damo-jian", 150);
        set_skill("fengyun-shou", 150);
        set_skill("fumo-jian", 150);
        set_skill("jingang-quan", 150);
        set_skill("longzhua-gong", 150);
        set_skill("luohan-quan", 150);
        set_skill("nianhua-zhi", 150);
        set_skill("pudu-zhang", 150);
        set_skill("qianye-shou", 150);
        set_skill("sanhua-zhang", 150);
        set_skill("weituo-gun", 150);
        set_skill("wuchang-zhang", 150);
        set_skill("xiuluo-dao", 150);
        set_skill("yingzhua-gong", 150);
        set_skill("yizhi-chan", 150);
        set_skill("zui-gun", 150);

        map_skill("blade", "cibei-dao");
        map_skill("claw", "longzhua-gong");
        map_skill("club", "wuchang-zhang");
        map_skill("cuff", "luohan-quan");
        map_skill("finger", "nianhua-zhi");
        map_skill("hand", "fengyun-shou");
        map_skill("staff", "weituo-gun");
        map_skill("strike", "sanhua-zhang");
        map_skill("sword", "fumo-jian");

        set("inquiry", ([
                "伏魔刀"     : (: ask_me :),
        ]));
        set("count",random(5)-3);
        setup();
        carry_object("/d/shaolin/obj/changbian")->wield();
}

void init()
{
        object me, ob;
        mapping fam;

        me = this_player();
        ob = this_object();

        ::init();
        if( interactive(me) ) 
        {
                if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
                && fam["generation"] == 36 ) return;

                if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
                && fam["generation"] > 36               
                && me->query("qi") < 50 ) 
                {
                        me->move("/d/shaolin/qyping");
                        me->unconcious();
                        return;
                }

                me->set_temp("3du-ok",1);
                COMBAT_D->do_attack(ob, me, query_temp("weapon") );
                

                ob->fight_ob(me);
                me->fight_ob(ob);

                call_out("halt", 10);

                return;
        }

        return;
}

void halt()
{
        command("say 好吧，大家住手！ 看这家伙有什么话要说！");
        command("halt");
        this_player()->set_temp("fighter", 1);
}

string ask_me()
{
//        mapping fam; 
        object ob;
        
        if ( !this_player()->query_temp("fighter") 
        ||    this_player()->query("combat_exp") < 100000 
        ||    this_player()->query("age") < 20 )
        {
                command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
                this_object()->kill_ob(this_player());
                this_player()->kill_ob(this_object());
        }
        
//        if ( (uptime() < 32000) || (time() - atoi(read_file(Last_Time)) < 10800) )
//                return "宝刀还没有。";

        if ( present("fumo dao", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "宝刀只有一把，而且就在你身上，真是贪得无餍！";

        if ( present("fumo dao", environment()) )
                return RANK_D->query_respect(this_player()) + 
                "宝刀只有一把，而且就在这里任你取走，真是贪得无餍！";

        if ( present("jingang zhao", this_player()) || present("jingang zhao", environment()) )
                return RANK_D->query_respect(this_player()) + 
                "取了金刚罩，就不能再拿伏魔刀，莫要贪得无餍！";

        if (query("count") < 1)
                return "抱歉，你来晚了，伏魔刀已经给人取走了。";

        ob = new("/d/shaolin/obj/fumo-dao");

        ob->move(this_player());
        
        write_file(Last_Time, ""+time(), 1);
        add("count", -1);

        message_vision("\n渡厄长笑一声，点点头，从身后的树洞里取出伏魔刀交给$N。\n\n", this_player());
        
         message("channel:rumor", HIM"【"+HIR+"谣言"+HIM+"】"+HIR+"某人："+this_player()->query("name")+"得到伏魔刀啦。\n"NOR, users());

        return "你既然能闯进金刚伏魔圈来，必然是当今武林中的非凡人物，这把刀是适逢其主了！";
}

void die()
{
        write_file(Last_Time, ""+time(), 1);
        ::die();
}

#include "/kungfu/class/shaolin/du.h"
