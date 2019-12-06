// shan.c

inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
        set_name("����", ({ "shan zheng" }));
	set("nickname", HIB"�����й�"NOR);
	set("age", 63);
	set("str", 25);
	set("dex", 16);
	set("per", 22);
	set("long", 
"����ƽ�������ֻҪ֪����������ʲô������֮�£���Ȼ����
Ҫ�ܡ���������⣬������ͯ�պ׷������֣�����ȴ��ǫ�ͣ�
���ƽ����ϴ�˵�ĳ������顣\n");
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
message_vision("������$N����һ������������С��ɫ���������������\n",me);
             return 1;
      }
        if(combatexp>3000000) {
message_vision("������$NӴ��һ���������С�¾Ͳ��鷳�������ˣ��п��������Ұ���\n",me);
             return 1;
      }

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
message_vision("������$N����һЦ����������������ˣ�\n", me);
message_vision("�������$Nһ��˵������Ҫ��û���£����õ�����ó������ñ����ȥ�������塣\n",me);
                   return 0;
             }
             else
             {
message_vision("��������$N̾��һ�����������Ҿ��ٸ���һ�λ���ɡ�\n", me);
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

 //       while (quest["quest_type"] == "ɱ")
 //       {
 //       quest = QUEST_D(tag)->query_quest();
 //       timep = quest["time"];
 //       }

        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
             tell_object(me,"�����Ұѡ�"+quest["quest"]+"������ɱ�ˣ���Ĳ�ʹ�Ժ���˵��\n" NOR);
        else
             tell_object(me,"���һء�"+quest["quest"]+"�����ң���Ĳ�ʹ�Ժ���˵��\n" NOR);
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

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,HIW "�����Ը�����������" + time + "��");
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
                   message_vision("����Ц�������ҿɾͲ������ˡ�\n",who);
                   call_out("destory",1,ob);
                   return 1;
             }
             if ( ob->value() < 5000)
             {
message_vision("����һ˫�������۾�ֱ����$N�����Ǯ�ɲ������ǵĿ�����\n", who);
                   call_out("destory",1,ob);
                   return 1;
             }
             else
             {
message_vision("����Ц�����Ǻã������������������ڡ����ֲ�ʹ�����Ұɣ�\n",who);
                   who->set("quest",0);
                   call_out("destory",1,ob);
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"����˵�����ⲻ������Ҫ�ġ�\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
             tell_object(who,"����˵��������ʲô�������ҽ����Ĳ�ʹ���������Ū����\n");
             return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"����˵�������Ƿ����û����ָ����ʱ���ڻ�����\n");
             return 0;
        }
        else
        {
             tell_object(who,"��������ص�ͷ˵����������ʹ��û�����\n");
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
             tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
               + "��ʵս���飬"+ chinese_number(pot) + "��Ǳ�ܣ�"
               + chinese_number(score)+"�㽭��������\n"NOR);
             who->set("quest", 0 );
             tell_object(who,HIW"��ϲ�����һ����ʹ��\n"NOR);
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