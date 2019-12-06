// dubi.c ��������

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);

void create()
{
	set_name("��������", ({ "dubi shenni", "dubi" }));
	set("gender", "Ů��");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "����һλ����Ů�ᣬ���շ�����Ŀ��ǰ����\n"+
	"һֻ����տ���Ҳ�����Ƕ���һ�ۣ�������ˣ�\n"+
	"��Ȼ�ڲ�ס�����˵ķ�ɡ�\n");
	set("combat_exp", 200000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("whip", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 90);
	set_skill("qiufeng-chenfa", 150);
	set_skill("shenxing-baibian", 150);
	map_skill("whip", "qiufeng-chenfa");
	map_skill("parry", "qiufeng-chenfa");
	map_skill("dodge", "shenxing-baibian");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 40);
	set_temp("apply/damage", 100);
	set("neili", 1500); 
	set("max_neili", 1500);
	set("jiali", 100);
        set("inquiry", ([
                "����" :  "����̾��һ������˵���������ҵĵ�����ӣ�\n�˳���ͦ��������ֻ��ϧ��ΤС��ƭȥ�ˡ�\n",
        ]) );
	setup();
        carry_object("/d/city2/obj/fuchen")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 2);
}

void init()
{
        object ob = this_player();

        if( ob && interactive(ob) ) {
                ::init();
                add_action("do_skills","skills");
                add_action("do_skills","cha");        
                remove_call_out("greeting");
                call_out("greeting", 1, ob );
        }
}

int recognize_apprentice(object ob)
{
    if ((ob->query("weiwang")+ob->query("meili"))<60)
    {
    message_vision("$Nҡ��ҡͷ��\n",this_object());
    command("tell "+ob->query("id")+"�����ز���ʶ��Ϊʲô��һ��Ҫ�����أ� \n"); 
    return 0;
    }
    return 1;	
}

int do_skills(string arg)
{
        object ob ;

        ob = this_player () ;

        if( !arg || arg!="dubi" )
                return 0;
        if(wizardp(ob))
                return 0;
        if (ob->query("weiwang")<60) {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                write("����Ů��˵��������ô�ܿ��ҵ��书�أ�\n");
                return 1;
        }
   command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - ��ɲ� 150/    \n"+
"  �����ڹ� (force)                         - һ����ʦ  90/    \n"+
"  �����м� (parry)                         - һ����ʦ  90/    \n"+
"  ����ȭ�� (unarmed)                       - һ����ʦ  90/    \n"+
"  �����޷� (whip)                          - ��ɲ� 150/    \n"+
"����糾�� (qiufeng-chenfa)                - ��ɲ� 150/    \n"+
"�����аٱ� (shenxing-baibian)              - ��ɲ� 150/    \n");
        return 1;
}

void greeting(object ob)
{
        int i; 
        object man,*obj;

        man=this_object();

        if( environment(man)->query("no_fight") ) {
                tell_room(environment(man),"�����������������������ˣ�����ô�ᵽ�������أ�\n˵�ž����˳�ȥ��\n");
        //        man->move("/d/city2/kedian3");
                destruct(this_object());
                return;
        }
        message_vision("$N̤��������ֻ������Ů���£���Ϣ��ֹ��\n",ob);         
        if( !ob || environment(ob) != environment())
                return;
    
        if((int)ob->query_temp("hastrystab")==6) {
                message_vision(HIC "$N̤��������ֻ������ʬ���£�һ��Ů�ᴭϢ��ֹ��\n" NOR,ob);         
                ob->delete_temp("hastrystab");
                ob->delete_temp("warned2");
                message_vision("\n����Ů���$N˵��������л��λ"+RANK_D->query_respect(ob)+
                "�ε�������ƶ��м�����������Ϊ����\n������һ�����аٱ���������Ըѧ��ƶ�ᶨ�������ڡ���\n",ob);
                if(ob->query("weiwang")<60) {
                        ob->add("weiwang",10);
                        message_vision(HIC "$N�Ľ�����������ˣ�\n" NOR,ob);
                        command("tell "+ob->query("id")+" �����ڵĽ��������� " +(string)(ob->query("weiwang")));
                        return ;
                }
                message_vision(HIC "����Ů���$N΢΢һЦ��\n" NOR,ob);   
                return;
        }
        obj = all_inventory(environment(ob));
        for(i=0; i<sizeof(obj); i++) {
                if( !living(obj[i]) || userp(obj[i]) || obj[i]==man ) continue;
                if( !userp(obj[i]) ) { 
                        man->set_leader(obj[i]);
                        man->kill_ob(obj[i]);
                        obj[i]->fight_ob(man);
		}
	}
        return ;
}
