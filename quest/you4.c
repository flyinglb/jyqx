// right_killer.c
// modified by wind

#include <ansi.h>
inherit NPC;
int time_period(int timep,object me);

void create()
{
        string quest;
        set("chat_chance", 25);

        set_name("����", ({ "right" }) );
        set("title", "��ɱ���ҽ���ʹ");
        set("gender", "Ů��" );
        set("age", 28);
        set("str", 30);
        set("int", 24);
        set("cps",30);
        set("long",
                "��ɱ���ҽ���ʹ����нӰ�ɱ�����⡣\n");
        set("combat_exp", 2000000);
        set("attitude", "heroism");

        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 10);

        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("whip", 120);
        map_skill("whip", "snowwhip");

       set("inquiry", ([  "��ɱ��": "�����˵, С�Ĺ�����������! \n",
        ]) );

        setup();
}
int accept_fight(object me)
{
        command("say С�ӣ��������ɱ��, ��Ҫ���ˣ�");
        return 0;
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
        message_vision("���Ķ�$N����һ����: ����С��ɫ��������ɱ��, ��Ҳ�����˼
����....\n",me);
         return 1;
          }

// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
        {
          message_vision("���Ķ�$N���ĵ�һЦ��: ��Ҫ��ɱ�ų���, �����Ȱ����������ɰɡ�\n", me);
                  message_vision("Ȼ����ͷ��������˵������Ҫ�Ǿ����������͵ø���������ˡ�\n",me);
          return 0;
        }
        else
        {
          message_vision("���Ķ���$N̾��һ����:�����Ҿ��ٸ���һ�λ���ɡ�\n", me);
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
        } else {
                if ((num<sizeof(levels)-1)&&(random(100)>95))
                {
                num=num+1;
                factor=15;
                }
        }
        tag=levels[num];
        quest = QUEST_D(tag)->query_quest();
        timep = quest["time"];

 //       while (quest["quest_type"] == "ɱ")
 //       {
 //       quest = QUEST_D(tag)->query_quest();
 //       timep = quest["time"];
 //       }

        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
        tell_object(me,"������ɱ�ˡ�"+quest["quest"]+"��,�����Ҹ�����ɱ�֡�\n" NOR);
        else
        tell_object(me,"���һء�"+quest["quest"]+"������,�����Ҹ�����ɱ�֡�\n" NOR);
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

        tell_object(me,HIW "����˵����\n��" + time + "��");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        string test;
        mapping quest;

                if (ob->query("money_id"))
                {
                        if(!who->query("quest"))
                        {
              message_vision("����Ц��: ���ҿɾͲ������ˡ�\n",who);
                          return 1;
                        }
                        if ( ob->value() < 10000)
                        {
                                message_vision("����һ˫�������۾�ֱ����$N:���Ǯ�ɲ������ǵĿ���ѽ!\n", who);
                                return 1;
                        }
                        else
                        {
              message_vision("����Ц��: �Ǻã������������������ڡ����������Ұɣ�\n",who);
                          who->set("quest",0);
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
        tell_object(who,"����˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"����˵�������ϧ����û����ָ����ʱ���ڻ�����\n");
        destruct(ob);
        return 0;
        }

        else
        {
        tell_object(who,"����˵�����Բ���������ɱ�Ż�������ɱ�֣�\n");
        exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
        pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
        score = quest["score"]/2 + random(quest["score"]/2);
        factor=who->query("quest_factor");
        destruct(ob);

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
        bonus += (int) who->query("learned_points");
        who->set("potential", bonus );
        bonus = (int) who->query("score");
        bonus += score;
        who->set("score", bonus);
        tell_object(who,HIW"�㱻������\n" + chinese_number(exp)
          + "��ʵս����\n"+ chinese_number(pot) + "��Ǳ��\n"
          + chinese_number(score)+"���ۺ�����\n"NOR);
        who->set("quest", 0 );
         return notify_fail("��ϲ�����һ������\n");;
        }
     return 1;
}
