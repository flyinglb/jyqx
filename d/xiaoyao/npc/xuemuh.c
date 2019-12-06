//xuemuh.c 薛慕华
// edward.2000.3

inherit NPC;
inherit F_MASTER;
#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

int ask_me();
int ask_tool();
void do_dest(object obj);

//void attempt_apprentice(object ob);
void create()
{
        set_name(HIC"薛慕华"NOR, ({ "xue muhua", "xue" }));
        set("long", 
                HIC"他就是号称阎王敌的神医——薛慕华，据说他精通医理，可以起死回生。\n"NOR);
        set("gender", "男性");
        set("title","逍遥派"MAG"“函谷八友”");
        set("nickname",HIY"阎王敌薛神医"NOR);
        set("age", 50);
        set("class", "shaman");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 25);
        set("dex", 25);
        set("inquiry", ([
                "疗伤" : (:ask_me:),
                "工具" : (:ask_tool:),
                "tool" : (:ask_tool:),
        ]) );

        set("max_qi", 1500);
        set("max_jing", 600);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);
        set("combat_exp", 150000);
        set("score", 80000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
        set_skill("lingboweibu",90);
        set_skill("beiming-shengong", 90);
        set_skill("zhemei-shou", 90);
        set_skill("literate",100);
        set("chat_chance", 2);
        set("chat_msg", ({
                HIC"薛慕华"NOR"说到：""我要练丹了。谁吃了它.......\n",
                HIC"薛慕华"NOR"说到：""你问我疗伤的方法，我可不会说\n",
        }) );


        map_skill("unarmed", "zhemei-shou");
        map_skill("dodge", "lingboweibu");
        map_skill("force", "beiming-shengong");

//      prepare_skill("hand","zhemei-shou");

        create_family("逍遥派", 3, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
        command("recruit " + ob->query("id"));
 }

int ask_me()
{
        object ob;
        ob=this_player();

        if (ob->query("family/family_name") != "逍遥派")
                return notify_fail("不行！你不是我派弟子，我不可以为你疗伤。你到别的地方去吧\n");
        if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
        {
                command("?"+ob->query("id"));     
                command("say 你没有受任何伤啊？\n");
                return 1;
        }
        else
        {
                message_vision("薛慕华喂$N服下一颗药丸,然后双掌贴着$N的背心。\n", ob);
                remove_call_out("recover");
                call_out("recover",2,ob);
                return 1;
        }
}

int ask_tool()
{
        object who;
        who = this_player();
if(!who->query_temp("job_xiaoyao") || who->query("family/family_name") != "逍遥派") {
                write(name()+"对你说道：你要这玩意干吗？\n");
                 return 1;
        }
        if( objectp(present("yao chu", who)) ) {
                write(name()+"对你说道：你不是有药锄吗？快去采药来，我等着用呢。\n");
                return 1;
        }
        message_vision(name()+"对$N说道：是掌门让你来帮忙来了？那就帮我去药谷采药吧！\n", who);
        who->set_temp("job_xiaoyao_tool",1);//给工具标记
        new(__DIR__"obj/yaochu")->move(who);
        tell_object(who, name()+"给你一把药锄。\n"); 
        return 1;
}

int accept_object(object who, object ob)
{
        if (ob->query("id") == "cao yao" && ob->name() == "草药" && ob->query("job") ) {
                if( ob->query_temp("finish_id") != who->query("id") ) {
                message_vision(name()+"对$N怒道：别人的东西你也好意思拿给我？\n", who);
                return 0;
                } else {
                message_vision(name()+"对$N说道：干的不错，辛苦你了！\n", who);
                ob->delete_temp("finish_id");
                who->add("combat_exp",400+random(20));
                who->add("potential",30+random(10));
                call_out("do_dest",1,ob);
                return 1;
                }
            }
        message_vision(name()+"对$N说道：这不是我想要的。\n", who);
        return 0;
}

void do_dest(object obj)
{
        if(!objectp(obj)) return;
        obj->move(find_object(VOID_OB));//减去负重
        destruct(obj);
}

int recover(object ob)
{
        ob->set("eff_qi", (int)ob->query("max_qi"));
        ob->set("eff_jing", (int)ob->query("max_jing"));  
        message_vision("大约过了一盅茶的时份，薛慕华慢慢收回双手。。\n",ob);
        command("say 你的伤势已经全好了,可以走啦。\n");
        return 1;
}
    
