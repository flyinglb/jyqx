// /kungfu/class/xueshan/gelunbu.c  葛伦布
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

#define GE_TIME "/data/npc/gelunbu.time"

string ask_fashi();
void do_dest(object ob);

void create()
{
        set_name("葛伦布", ({ "gelunbu", "ge" }));
        set("long",@LONG
葛伦布是雪山寺中护寺僧兵的头领。同时向本寺第子传授武功。
身穿一件黑色袈裟，头带僧帽。
LONG
        );
        set("title", HIY "喇嘛" NOR);
        set("nickname", HIG "僧兵头领" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 30);
        set("int", 20);
        set("con", 28);
        set("dex", 25);

        set("max_qi", 1000);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 100000);
        set("score", 40000);

        set_skill("lamaism", 70);
        set_skill("literate", 30);
        set_skill("force", 80);
        set_skill("xiaowuxiang", 80);
        set_skill("dodge", 75);
        set_skill("shenkong-xing", 70);
        set_skill("parry", 60);
        set_skill("staff", 80);
        set_skill("xiangmo-chu", 70 );
        set_skill("unarmed", 60);
        set_skill("yujiamu-quan", 60);
        set_skill("sword", 60);
        set_skill("mingwang-jian", 60);

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("sword","mingwang-jian");
        map_skill("unarmed","yujiamu-quan");
        set("inquiry", ([
                "准备法事" : (: ask_fashi :),
                "法事" : (: ask_fashi :),
        ]));

        create_family("雪山寺", 5, "喇嘛");
        set("class", "bonze");

        setup();

        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/senggun")->wield();

        add_money("silver",100);
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        int bonus, tmp;

//      if( !ob || environment(ob) != environment() ) return;
        if( environment(ob)->query("short") != "雪山祭坛" ) return;
        if (!(int)ob->query_temp("作法事")) return;

message_vision("葛伦布急急忙忙吩咐小喇嘛们往祭坛里填柴，倒酥油。\n\n", ob);
message_vision(HIR"$N点燃了祭坛中的木柴与酥油，熊熊烈火冲天而起。\n", ob);
message_vision(HIB"一丝魂魄升出祭坛，冉冉而起。魂魄受$N佛法感召，徘徊不去。\n", ob);
message_vision(RED"$N端起颅钵吸进一口水，「噗」的一声猛地朝那熊熊火焰喷将过去。\n", ob);
message_vision(HIC"$N盘腿打坐，神光内蕴，口中念念有辞，渐渐有一丝魂魄在$N面前凝聚成形。\n", ob);
message_vision(HIG"魂魄越聚越多，竟然呈出人形！$N手指人形，口念真言，指引往生之路。\n", ob);
message_vision(HIW"$N手持法铃，边走变摇，高声诵读密传经咒。突然大喝一声。声似雷霆。\n", ob);
message_vision(HIY"大院里光芒四起，一声巨响过后，又恢复了平静。超度完毕。\n"NOR, ob);
        if (ob->query_temp("作法事") > ob->query("combat_exp")) {
                bonus= ob->query_skill("lamaism",1) / 2;
                if (!ob->set_temp("玩家法事"))
                        tmp = (int)ob->query("combat_exp") * 2 * bonus /100000 ;
                else 
                        tmp = (int)ob->query("combat_exp") * 2 * bonus /10000 ;
                if( tmp > 1000 ) tmp = 1000;
                ob->add("combat_exp",tmp);
        }
        else
message_vision(HIR"\n$N不知道哪里找了个菜鸟煞有介事地来超度，看来是白忙了。\n"NOR, ob);
        ob->delete_temp("作法事");
        write_file(GE_TIME,""+time(),1);
}

void attempt_apprentice(object ob)
{

        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }

        command("say 我就传你一些武功吧！");
        command("recruit " + ob->query("id"));

        if((string)ob->query("class") != "bonze")       {
                ob->set("title","雪山派俗家弟子");
        }
        else    {
                ob->set("title",HIY"小喇嘛"NOR);
        }
}

string ask_fashi()
{
        mapping fam; 
        object ob = this_player();
        
        if( environment(this_object())->query("short") != "雪山寺山门" )
                return "这里正在做法事，你没看见麽？";
        if( (time() - atoi(read_file(GE_TIME))) < 60*30 )
                return "我刚做完法事，短时间内无法在做了。";
        if (!(fam = ob->query("family")) || fam["family_name"] != "雪山寺")
                return "你是那里跳出来的毛虫，也能做个屁法事？";
        if ( ob->query_skill("lamaism",1) < 30)
                return "你的密宗心法还早得很呢，没法让你开坛做法事。";
        ob->set_temp("法事",1);
        return "这位上人是要给哪位施主做法事呀？";
}

int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("法事"))
        {
                message_vision("葛伦布笑着对$N说：这种臭东西给我有什么用，您还是自己留着吧！\n", who);
                return 0 ;
        }
        who->delete_temp("法事");
        if (ob->query("id") == "corpse")
        {
                message_vision("葛伦布笑着对$N说：那我们去祭坛吧！\n", who);
                who->set_temp("作法事", ob->query("combat_exp"));
                if ((int)ob->query("userp"))
                        who->set_temp("玩家法事", 1);
                tell_room(environment(this_object()), name() + "往北走了出去。\n",this_object());
                this_object()->move("/d/xueshan/jitan");
                tell_room(environment(this_object()), name() + "走了过来。\n",this_object());
                call_out("do_dest",1,ob);
                return 1;
        }
        else  
                message_vision("葛伦布对$N说：这种东西还能做法事？直接埋了省事。\n", who);
        return 0;
}

void do_dest(object ob)
{
        if(!objectp(ob)) return;
        ob->move(VOID_OB);
        destruct(ob);
}
