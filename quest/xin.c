// wei.c

inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
	set_name("信使", ({ "xin shi", "xin", "shi" }));
	set("gender", "男性");
	set("age", 18);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 20);
	set("per", 28);
	set("combat_exp", 50000);
	set("attitude", "peaceful");
        set("neili", 500);
        set("max_neili", 500);

	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
}

void init()
{
        add_action("give_quest", "quest");
}

int give_quest()
{
        mapping quest ;
        object me,xin;
  int j, combatexp, timep,factor,num,pot;
        string tag = "1000000";
        string *levels = ({
                        "1000",
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
        if(combatexp >= 500000 )
{
message_vision(HIR"这点小事，就不麻烦大侠你了。\n"NOR,me);
             return 1;
            }
          if(combatexp <= 50000 )
          {
message_vision(HIR"你的能力还不够,先去做点体力活吧！\n"NOR,me);
              return 1;
}
    pot = (int) (me->query("potential"))- (int) (me->query("learned_points"));
  if(pot >= 10 * (me->query_int()) )
{
 message_vision(HIY"搞这么多潜能干嘛？快学了!\n"NOR,me);
   return 1;
}
        if( me->query("questname"))
        {
message_vision(HIW"还不快点把信送了？”\n"NOR,me);
             return 1;
        }

// Let's see if this player still carries an un-expired task
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
//        quest = QUESTX_D(tag)->query_quest();
        quest = "/quest/qxlist1000.c"->query_quest();
        timep = quest["time"];

        time_period(timep, me);
	tell_object(me,HIW"把信送到『"HIC+quest["quest"]+HIW"』，我会好好谢你。\n" NOR);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];
	xin = new("/d/city/npc/obj/xin.c");
	xin ->move(me);
	tell_object(me,HIW"我把信给你，要保管好。\n" NOR);

//        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        me->set("questname",quest["quest"]);
	me->set("questexp",300);
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
        return 1;
}

int accept_object(object who, object ob)
{
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("questname"))
             {
                   message_vision("信使笑道：那我可就不客气了。\n",who);
                   return 1;
             }
             if ( ob->value() < 2000)
             {
message_vision("信使一双尖针般的眼睛直盯着$N：这点钱可不够我们的开销！\n", who);
                   return 1;
             }
             else
             {
message_vision("信使笑道：那好，咱们买卖不成仁义在。想要好处再找我吧！\n",who);
                   who->delete("questname");
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"信使说道：这不是我想要的。\n");
             return 0;
        }
}
