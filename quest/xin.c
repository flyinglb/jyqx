// wei.c

inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
	set_name("��ʹ", ({ "xin shi", "xin", "shi" }));
	set("gender", "����");
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
message_vision(HIR"���С�£��Ͳ��鷳�������ˡ�\n"NOR,me);
             return 1;
            }
          if(combatexp <= 50000 )
          {
message_vision(HIR"�������������,��ȥ����������ɣ�\n"NOR,me);
              return 1;
}
    pot = (int) (me->query("potential"))- (int) (me->query("learned_points"));
  if(pot >= 10 * (me->query_int()) )
{
 message_vision(HIY"����ô��Ǳ�ܸ����ѧ��!\n"NOR,me);
   return 1;
}
        if( me->query("questname"))
        {
message_vision(HIW"�������������ˣ���\n"NOR,me);
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
	tell_object(me,HIW"�����͵���"HIC+quest["quest"]+HIW"�����һ�ú�л�㡣\n" NOR);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];
	xin = new("/d/city/npc/obj/xin.c");
	xin ->move(me);
	tell_object(me,HIW"�Ұ��Ÿ��㣬Ҫ���ܺá�\n" NOR);

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

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        return 1;
}

int accept_object(object who, object ob)
{
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("questname"))
             {
                   message_vision("��ʹЦ�������ҿɾͲ������ˡ�\n",who);
                   return 1;
             }
             if ( ob->value() < 2000)
             {
message_vision("��ʹһ˫�������۾�ֱ����$N�����Ǯ�ɲ������ǵĿ�����\n", who);
                   return 1;
             }
             else
             {
message_vision("��ʹЦ�����Ǻã������������������ڡ���Ҫ�ô������Ұɣ�\n",who);
                   who->delete("questname");
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"��ʹ˵�����ⲻ������Ҫ�ġ�\n");
             return 0;
        }
}
