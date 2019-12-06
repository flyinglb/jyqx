// NPC : /d/city/npc/zongguan.c

inherit NPC;
#include <ansi.h>;

int time_period(int timep,object me);
void get_list( string get_sel,object me);
mapping quest1,quest2,quest3,quest_dummy,quest;
int wait_tag;


void create()
{
        set_name(HIY"��վ�ܹ�"NOR, ({ "zong guan", "zongguan"}));
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

void init() { add_action("give_quest", "quest"); }

void get_list( string get_sel,object me)
{
        int timep,factor;
        object xin;
        if (wait_tag)
          {
              //tell_object(me,HIM"\n���ӻ��кܶ�����Ҫ���أ�����ô����������ô���У�\n" NOR);
              this_object()->delete_temp("busy");
              this_object()->delete_temp("quest_id");
              return;
          }

        remove_call_out("force_end_select");
        switch (get_sel) {
               case "1" :
                       quest=quest1;
                       break;
                case "2" :
                        quest=quest2;
                        break;
                case "3" :
                        quest=quest3;
                        break;
                default  :
                        tell_object(me,HIW"�����ѡһ������"NOR);
                        input_to("get_list", me);
                        return ;
        }
        

        time_period(timep, me);
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];
        
        xin = new(__DIR__"obj/xin.c");
        xin ->move(me);
        
        tell_object(me,HIW"�ð�,���ϡ�"HIC+quest["quest"]+HIW"��������һ�˰�.\n" NOR);
        tell_object(me,HIW"�Ұ��Ÿ��㣬Ҫ���ܺá�\n" NOR);
        
        me->set_temp("quest_songxin",([
                "quset_name" : quest["quest"],
                "time"          :(int) time()+(int) quest["time"],
                "factor"        :factor,
                "questexp"  : 300,
                "questlist"  : 0,
        ]) );
        
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
        me->set("questname",quest["quest"]);
        me->set("questexp",300);
        
        this_object()->delete_temp("busy");//ɾ�����
        this_object()->delete_temp("quest_id");
        
        return ;
}
int give_quest()
{
          object me,ob;
         int j, combatexp,factor,num,pot;
          string who;
        string tag = "1000000";
        string *levels = ({ "1000", });
        me = this_player();
        wait_tag=0;
        combatexp = (int) (me->query("combat_exp"));
        
        //find player
        if( stringp(who = this_object()->query_temp("quest_id")) ) {
                ob = present(who, environment(this_object()));
                if( !ob ) {
                        this_object()->delete_temp("busy");//ɾ�����
                        this_object()->delete_temp("quest_id");
                } else {
                        if( ob->query_temp("netdead") ) {
                                this_object()->delete_temp("busy");//ɾ�����
                                this_object()->delete_temp("quest_id");
                        }
                }
        } else {
                this_object()->delete_temp("busy");//ɾ�����
                this_object()->delete_temp("quest_id");
        }
        
        if( !me->query("questname") && (me->query("id") == query_temp("guest_id"))) {
                        this_object()->delete_temp("busy");//ɾ�����
                        this_object()->delete_temp("quest_id");
        }                
        //find end
        
        if ( this_object()->query_temp("busy") ) {
                message_vision(CYN"�ܹ�����һ������$N˵������ʲô��û��������æô��\n"NOR,me);
                return 1;
        } else {
                this_object()->set_temp("busy",1); //���ñ��
                this_object()->set_temp("quest_id",me->query("id"));
        }

        if(combatexp >= 500000 ) {
                tell_object(me, CYN"�ܹܶ���˵���������С�£��Ͳ��鷳�������ˡ���\n"NOR);
                this_object()->delete_temp("busy");//ɾ�����
                this_object()->delete_temp("quest_id");
                return 1;
        }
        
        if(combatexp <= 50000 ) {
                tell_object(me, CYN"�ܹܶ���˵�������������������,��ȥ����������ɣ���\n"NOR);
                this_object()->delete_temp("busy");//ɾ�����
                this_object()->delete_temp("quest_id");
                return 1;
        }
        
        pot = (int) (me->query("potential"))- (int) (me->query("learned_points"));
        
        if(pot >= 50 * (me->query_int()) ) {
                tell_object(me, CYN"�ܹܿ�����һ��˵������������ʱû��ʲô�¸�������\n"NOR);
                this_object()->delete_temp("busy");//ɾ�����
                this_object()->delete_temp("quest_id");
                return 1;
        }
        
        if( me->query("questname")) {
                tell_object(me, CYN"�ܹܶ���ȵ������������ȥ���Ұ������ˣ���\n"NOR,me);
                this_object()->delete_temp("busy");//ɾ�����
                this_object()->delete_temp("quest_id");
                return 1;
        }

        for(j= sizeof(levels) - 1 ; j>=0; j--) {
             if( atoi(levels[j])  <= combatexp ) {
                   num=j;
                   factor=10;
                   break;
             }
        }
        
        if (num>0) {
             if (random(50)>45) num=num-1;
        } else {
             if ((num<sizeof(levels)-1)&&(random(100)>95)) {
                   num=num+1;
                   factor=15;
             }
        }

        tag=levels[num];
        quest1 = "/quest/qxlist1000.c"->query_quest();
        quest2 = "/quest/qxlist1000.c"->query_quest();
        quest3 = "/quest/qxlist1000.c"->query_quest();
        
        tell_object(me,HIW + "������3���ŵ��ŷ���ȥ,��Ҫѡ�Ǹ�����?\n" +
        "1.��"HIC+quest1["quest"]+HIW"��\n" + 
        "2.��"HIC+quest2["quest"]+HIW"��\n" +
        "3.��"HIC+quest3["quest"]+HIW"��\n" NOR);
        remove_call_out("force_end_select");
        call_out("force_end_select",5,me);
        input_to("get_list",me);
        return 1;
}

void force_end_select(object me)
{
        wait_tag=1;
        get_list("",me);
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


        if(!who->query("questname")) {
                tell_object(who,"�ܹ�˵�������ⲻ������Ҫ�ġ���\n");
                return 0;
        }

        if (ob->query("money_id")) {
             if(!who->query("questname")) {
                        message_vision("�ܹܶ�$NЦ�������ҿɾͲ������ˡ�\n",who);
                        //command("giggle " + who->query("id"));
                        command("giggle");
                        call_out("destory",1,ob);
                        return 1;
             }
             if ( ob->value() < 2000) {
                        message_vision("�ܹܵ�����������ֱ����$N�����Ǯ�ɲ����Ҵ򷢱��˵ģ�\n", who);
                        return 0;
             } else {
                        message_vision("�ܹܶ�$NЦ�����Ǻã������������������ڡ���Ҫ�ô������Ұɣ�\n",who);
                        who->delete("questlist");
                        who->delete("questname");
                        call_out("destory",1,ob);
                        return 1;
             }
        }
}

void destory(object ob)
{
    if(!ob) return;
    ob->move(VOID_OB);
    destruct(ob);
}