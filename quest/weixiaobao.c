// wei.c

inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
        set_name("ΤС��", ({ "wei xiaobao", "xiaobao" }));
	set("title", HIC"�������Զ�󽫾�"HIY"һ��¹����"NOR);
	set("gender", "����");
	set("age", 18);
          set("str", 50000);
	set("int", 30);
	set("con", 30);
	set("dex", 20);
	set("per", 28);
	set("long", 
"��λ���꽫��ͷ���춥�ӣ�������ӣ�ü����Ц����߯��
�⣬������ҡ���ȣ��������֮�������ֵ��ϴ󵶣�ٲȻ��
��֮��������Τ��С����Ҳ�����㿴��������������������
���Ц������ѧ����Ϸ���вܲٵ�ģ�������ʱ�̲�ס�ո�
Ȥ����һ�䣺������Ϊ�η�Ц����\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");
        set("max_qi", 2500);
        set("max_jing", 1000);
        set("neili", 500);
        set("max_neili", 500);
	set("jiali", 50);

        set_skill("force", 20);
        set_skill("parry", 20);
        set_skill("hand", 20);
        set_skill("dodge", 20);
        set_skill("shenxing-baibian", 20);
        set_skill("yunlong-shengong", 20);
        set_skill("qianye-shou", 90);

        map_skill("force", "yunlong-shengong");
        map_skill("parry", "qianye-shou");
        map_skill("dodge", "shenxing-baibian");
        map_skill("hand", "qianye-shou");
        prepare_skill("hand", "qianye-shou");
        set("inquiry", ([
            "��ػ�"  : "���ң�\n",
            "�½���"  : "������ʦ����\n",
            "éʮ��"  : "������ʮ�˸�ë�氡������û���ɣ�\n",
            "��������": "��������ò���ʦ����\n",
            "Τ����"  : "�������������Խ��Խ���ˣ����ڸ���������ˣ�\n",
            "����"    : "�����һʵ�ʦ����\n",
            "С����"  : "�����һʵ�ʦ����\n",
            "С����"  : "������������ˣ������£�\n",
            "����"    : "��������ý��Ȣ�Ĵ����ţ�\n",
            "˫��"    : "����ʶ�����󹦸�ɣ��׸������\n",
            "����"    : "������������ô�������Ϻ鸣���죬���޸����죡\n",
            "����"    : "������������ô�������Ϻ鸣���죬���޸����죡\n",
            "����"    : "������������ô�������Ϻ鸣���죬���޸����죡\n",
            "�彣��"  : "������������ô�������Ϻ鸣���죬���޸����죡\n",
            "��������": "���ɧ��Ƥ���׺񲻼�˫������ò�������桢�书��
�����������ɲ������������洿�Ʋ����彣��������˹�Ĳ������ᣬ
����һ��֮���ߣ����������������ѣ�\n",
        ]) );

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
        object me;
        int j, combatexp, timep,factor,num;
        string tag = "1000000";
        string *levels = ({
//			"1000",
//			"1500",
			"2000",
//			"3000",
//			"5000",
//			"8000",
//			"10000",
//			"13000",
//			"17000",
			"22000",
//			"30000",
//			"45000",
//			"60000",
//			"80000",
//			"100000",
			"200000"
//			"350000",
//			"600000",
//			"1000000"
        });
        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
        if(combatexp<1000)
        {
message_vision("ΤС����$N����һ���������������裬������û����������\n",me);
             return 1;
        }

        if(combatexp>3000000) {
message_vision("ΤС����$NӴ��һ���������С�¾Ͳ��鷳�������ˣ��п��������Ұ���\n",me);
             return 1;
      }


// Let's see if this player still carries an un-expired task
        if((quest =  me->query("quest")))
        {
             if( ((int) me->query("task_time")) >  time() )
             {
message_vision("ΤС����$NЦ����˵�㲻�аɣ�����������\n", me);
message_vision("ΤС�����$Nһ��˵������Ҫ��û���£����õ��Ǯ��͵��ˡ�\n",me);
                   return 0;
             }
             else
             {
message_vision("ΤС������$N̾��һ������û��ϵȥ�ñ��Ҳ�ɡ�\n", me);
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
        quest = QUESTW_D(tag)->query_quest();
        timep = quest["time"];

 //       while (quest["quest_type"] == "ɱ")
 //       {
 //       quest = QUEST_D(tag)->query_quest();
 //       timep = quest["time"];
 //       }

        time_period(timep, me);
        if(quest["quest_type"]=="ɱ")
             tell_object(me,"�����Ұѡ�"+quest["quest"]+HIW"��ץ���������뿴��������ɶģ����\n" NOR);
        else
             tell_object(me,"�ҵ���"NOR+quest["quest"]+HIW"�����ң��һ�ú�л�㡣\n" NOR);
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

        tell_object(me,HIW "ΤС���Ը�����������" + time + "��");
        return 1;
}

int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
//        string test;
        mapping quest;

        if (ob->query("money_id"))
        {
             if(!who->query("quest"))
             {
                   message_vision("ΤС��Ц�������ҿɾͲ������ˡ�\n",who);
                   call_out("destory",1,ob);
                   return 1;
             }
             if ( ob->value() < 2000)
             {
message_vision("ΤС��һ˫�������۾�ֱ����$N�����Ǯ�ɲ������ǵĿ�����\n", who);
                   call_out("destory",1,ob);
                   return 1;
             }
             else
             {
message_vision("ΤС��Ц�����Ǻã������������������ڡ���Ҫ�ô������Ұɣ�\n",who);
                   who->set("quest",0);
                   call_out("destory",1,ob);
                   return 1;
             }
        }

        if(!(quest =  who->query("quest")))
        {
             tell_object(who,"ΤС��˵�����ⲻ������Ҫ�ġ�\n");
             return 0;
        }

        if( ob->query("name") != quest["quest"])
        {
             tell_object(who,"ΤС��˵��������ʲô�������ҽ����������������Ū�ң���\n");
             return 0;
        }

        if ((int) who->query("task_time") < time() )
        {
             tell_object(who,"ΤС��˵�������Ƿ����û����ָ����ʱ���ڻ�����\n");
//             call_out("destory",1,ob);
             return 0;
        }
        else
        {
             tell_object(who,"ΤС������ص�ͷ˵����������ʹ��û�����\n");
               exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
              pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
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
             if( bonus > 3000) bonus = 3000;
//             if( bonus > who->query("int")*50 ) bonus = who->query("int")*50;
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
             return 1;
        }
        return 1;
}

void destory(object ob)
{
    if(!ob) return;
    ob->move(VOID_OB);
    destruct(ob);
}
