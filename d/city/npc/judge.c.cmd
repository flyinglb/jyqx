// judge.c
// modified by wind
inherit NPC;
void create()
{
        set_name("����", ({ "judge" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "�����ϵı���·��ǿ�������ڴ����Ǯһ�㡣\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);
        set("inquiry", ([
                "��" : "�͹�����Ǯ���Ҿ����ˡ�\n",
        ]) );
        setup();
        add_money("silver", 1);
	set("accept",1);
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/dagger")->wield();
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 0:
                        say( "�����ģ�����������\n");
                        break;
                case 1:
                        say( "Ӯ�˿�������������\n");
                        break;
        }
}
void pay_player(object who, int amount)
{
	object ob;
	if( amount < 1 ) amount = 1;
/*
        if( amount/10000000 ) {
		if (!ob=present("thousand-gold_money", who)){
	                ob = new(THGOLD_OB);
			if ( !ob->move(who) ){
				ob->set_amount(amount/10000000);
				ob->move(environment(who));
			}else	ob->set_amount(amount/10000000);
		}else   ob->add_amount(amount/10000000);
		amount %= 10000000;
	}
*/
        if( amount/100000 ) {
		if (!ob=present("thousand-silver_money", who)){
	                ob = new(THCASH_OB);
			if ( !ob->move(who) ){
				ob->set_amount(amount/100000);
				ob->move(environment(who));
			}else	ob->set_amount(amount/100000);
		}else   ob->add_amount(amount/100000);
		amount %= 100000;
	}
        if( amount/10000 ) {
		if (!ob=present("gold_money", who)){
	                ob = new(GOLD_OB);
			if ( !ob->move(who) ){
				ob->set_amount(amount/10000);
				ob->move(environment(who));
			}else	ob->set_amount(amount/10000);
		}else   ob->add_amount(amount/10000);
		amount %= 10000;
	}
	if( amount/100 ) {
		if (!ob=present("silver_money", who)){
	                ob = new(SILVER_OB);
			if (!ob->move(who)){
				ob->set_amount(amount/100);
				ob->move(environment(who));
			}else	ob->set_amount(amount/100);
		}else   ob->add_amount(amount/100);
		amount %= 100;
	}
	if( amount ) {
		if (!ob=present("coin_money", who)){
			ob = new(COIN_OB);
			if (!ob->move(who)){
				ob->set_amount(amount);
				ob->move(environment(who));
			}else	ob->set_amount(amount);
		}else   ob->add_amount(amount);
	}
}
int accept_object(object who, object ob)
{
        int val;
        val = ob->value();
        if( !val ){
                return notify_fail("��Ʒ�����ۼۣ���������ȥ���ְɣ�\n");
                return 0;
        }
        else{
                say("ʲô�� ��ѺС�����õġ�\n"); 
//                                destruct(ob);
                                remove_call_out("destory");
                                call_out("destory",1,ob);
				if( random(10) < 7 ) {
                        say( "����˵��������Ѻ���Ӯ������λ"
                                + RANK_D->query_respect(who)
                                + "�����´�һ�����ˣ�\n");
                }
                else{
                        say( "����˵��������ѺС��Ӯ������λ"
                                + RANK_D->query_respect(who)
                                + "���Ǻ��˵�����������Ӯͷ��\n");
                        pay_player(this_player(), val * 2);
                }
        return 1;
        }
}

void destory(object ob)
{
    if( objectp(ob) ) destruct(ob);
}
