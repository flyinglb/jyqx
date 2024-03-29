// shan.c

inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
        set_name("单正", ({ "shan zheng" }));
	set("nickname", HIB"铁面判官"NOR);
	set("age", 63);
	set("str", 25);
	set("dex", 16);
	set("per", 22);
	set("long", 
"他生平嫉恶如仇，只要知道江湖上有什么不公道之事，定然伸手
要管。他满脸红光，当得起“童颜鹤发”四字，神情却甚谦和，
不似江湖上传说的出手无情。\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	set("neili", 800); 
	set("max_neili", 800);
	set("jiali", 50);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num;
        string tag = "1000000";
        string *levels = ({
                        "1000",
                        "1500",
                        "2000",
                        "3000",
                        "5000",
                        "8000",
                        "10000",
                        "13000",
                        "17000",
                        "22000",
                        "30000",
                        "45000",
                        "60000",
                        "80000",
                        "100000",
                        "200000"
//                        "350000",
//                        "600000",
//                        "1000000"
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
        if(combatexp<1000)
        {
message_vision("单正对$N哼了一声道：“这种小角色还想除暴安良？”\n",me);
             return 1;
      }
        if(combatexp>3000000) {
message_vision("单正对$N哟了一声道：这点小事就不麻烦大侠你了，有空再来看我啊！\n",me);
             return 1;
      }

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
message_vision("单正对$N冷冷一笑道：让你办的事如何了？\n", me);
message_vision("单正瞟了$N一眼说道：你要是没本事，就拿点儿费用出来我让别的人去申张正义。\n",me);
                   return 0;
             }
             else
             {
message_vision("单正对着$N叹了一口气：哎，我就再给你一次机会吧。\n", me);
                   me->add("qi",-(int)(me->query("qi")/10));
             }
        }

        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];
        quest = QUESTS_D(tag)->query_quest();
        timep = quest["time"];

 //       while (quest["quest_type"] == "杀")
 //       {
 //       quest = QUEST_D(tag)->query_quest();
 //       timep = quest["time"];
 //       }

        time_period(timep, me);
        if(quest["quest_type"]=="杀")
             tell_object(me,"先替我把『"+quest["quest"]+"』给我杀了，别的差使以后再说。\n" NOR);
        else
             tell_object(me,"先找回『"+quest["quest"]+"』给我，别的差使以后再说。\n" NOR);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];

        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIW "单正吩咐道：给你在" + time + "内");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                   message_vision("单正笑道：那我可就不客气了。\n",who);
                   call_out("destory",1,ob);
                   return 1;
             }
             if ( ob->value() < 5000)
             {
message_vision("单正一双尖针般的眼睛直盯着$N：这点钱可不够我们的开销！\n", who);
                   call_out("destory",1,ob);
                   return 1;
             }
             else
             {
message_vision("单正笑道：那好，咱们买卖不成仁义在。想讨差使再找我吧！\n",who);
                   who->set("quest",0);
                   call_out("destory",1,ob);
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"单正说道：这不是我想要的。\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
             tell_object(who,"单正说道：这是什么东西？我叫你办的差使你就这样糊弄？！\n");
             return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"单正说道：真是废物！你没有在指定的时间内回来！\n");
             return 0;
        }
        else
        {
             tell_object(who,"单正赞许地点头说道：不错！差使办得还不错！\n");
              exp = quest["exp_bonus"]*2 + random(quest["exp_bonus"]/2);
             pot = quest["pot_bonus"]*2 + random(quest["pot_bonus"]);
             score = quest["score"]/2 + random(quest["score"]/2);
             factor=who->query("quest_factor");
             call_out("destory",1,ob);
             if (factor)
             {
                  exp=exp*factor/10;
                  pot=pot*factor/10;
                  score=score*factor/10;
             }
             bonus = (int) who->query("combat_exp");
             bonus += exp;
             who->set("combat_exp", bonus);
             bonus = (int) who->query("potential");
             bonus = bonus - (int) who->query("learned_points");
             bonus = bonus + pot;
             if( bonus > 300) bonus = 300;
//             if( bonus > (int)who->query("int")*50 ) bonus = (int)who->query("int")*50;
             bonus += (int) who->query("learned_points");
             who->set("potential", bonus );
             bonus = (int) who->query("score");
             bonus += score;
             who->set("score", bonus);
             tell_object(who,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战经验，"+ chinese_number(pot) + "点潜能，"
               + chinese_number(score)+"点江湖阅历。\n"NOR);
             who->set("quest", 0 );
             tell_object(who,HIW"恭喜你完成一个差使！\n"NOR);
             return 0;
        }
        return 1;
}

void destory(object ob)
{
    if(!ob) return;
    ob->move(VOID_OB);
    destruct(ob);
}