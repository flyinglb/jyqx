// modified by wind

#include <ansi.h>
inherit NPC;
int *stat =({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
void pay_him(object who, int amount);
void clear_stat();
void create()
{
        set_name( "��ʥ", ({ "gamester" }) );
        set("long", "���������ְҵ���֣������ϵĹ�������뻯��\n");
        set("attitude", "friendly");
        set("title", HIW "��ǧ��" NOR);
        set("jiali", 30);
        set("max_jing", 3000);
        set("max_qi", 3000);
        set("max_jing", 300);
        set("jing", 300);
        set("max_neili", 3000);
        set("meili", 3000);
        set("age", 33);
        set_temp("apply/damage",600);
        set("gender", "����" );
        set("str", 35);
        set("con", 30);
        set("cps", 25);
        set("per",5);
        set("lower_limit",1);
        set("too_late",0);
        set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0);
        set("max_force",400000);
        set_skill("throwing",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set("combat_exp", 50000000);
        setup();
        carry_object(__DIR__+"obj/cloth")->wear();
        carry_object(__DIR__"obj/guzi")->wield();
}
void init()
{
        object ob;
        ::init();
        if (base_name(environment())!=query("startroom")) return;
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_bet", "bet");
        
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "��ʥЦ�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������֣������İɡ�\n");
                        break;
                case 1:
                        say( "��ʥ���˻����е����ӣ��е�����λ" + RANK_D->query_respect(ob)
                                + "��С�Ŀ������Һ��ڣ���Ŀ��Զ���������ɣ�\n");
                        break;
                case 2:
                        say( "��ʥ˵������λ" + RANK_D->query_respect(ob)
                                + "�������������� �������ҵģ�\n");
                        break;
        }
        return;
}
 
string *dice = ({
HIW"
         ����������
         ��      ��
         ��  "+HIR+"��"+HIW+"  ��
         ��      ��
         ����������
"NOR,
HIW"
         ����������
         ��"+HIY+"��"+HIW+"    ��
         ��      ��
         ��    "+HIY+"��"+HIW+"��
         ����������
"NOR,
HIW"
         ����������
         ��"+HIY+"��"+HIW+"    ��
         ��  "+HIY+"��"+HIW+"  ��
         ��    "+HIY+"��"+HIW+"��
         ����������
"NOR,
HIW"
         ����������
         ��"+HIR+"��"+HIW+"  "+HIR+"��"+HIW+"��
         ��      ��
         ��"+HIR+"��"+HIW+"  "+HIR+"��"+HIW+"��
         ����������
"NOR,
HIW"
         ����������
         ��"+HIY+"��"+HIW+"  "+HIY+"��"+HIW+"��
         ��  "+HIY+"��"+HIW+"  ��
         ��"+HIY+"��"+HIW+"  "+HIY+"��"+HIW+"��
         ����������
"NOR,
HIW"
         ����������
         ��"+HIY+"��"+HIW+"  "+HIY+"��"+HIW+"��
         ��"+HIY+"��"+HIW+"  "+HIY+"��"+HIW+"��
         ��"+HIY+"��"+HIW+"  "+HIY+"��"+HIW+"��
         ����������
"NOR});



int do_bet(string arg)
{
        int i,bet_amt,amount;
        int bet_type;
        object me, money_ob;
        string message,money;
        if(!arg || !sscanf(arg, "%d %d %s",bet_type,amount,money))
                return notify_fail("bet <����> <����> <��������>\n");
        if(bet_type>18 || bet_type < 0)
                return notify_fail("����ֻ�ɴ��㵽ʮ��\n");
        me = this_player();
        if(me->is_busy())
                return notify_fail("���ϸ�������û��ɡ�\n");
                money_ob = present(money + "_money", me);
        if(!money_ob) return notify_fail("������û������Ǯ��\n");
                if (amount<0)   return notify_fail("������Ҫ��һ���ӡ�\n");
        if((int) money_ob->query_amount() < amount)
                return notify_fail("������û�������"+money_ob->query("name")+"��\n"); 
        if((int) this_object()->query("too_late") )
                return notify_fail("�����������ˣ������ְɣ�\n");
                bet_amt=amount * money_ob->query("base_value");
                if (me->query_temp("gamble/amount")+bet_amt<0
                || me->query_temp("gamble/amount")+bet_amt>10000000)
                        return notify_fail("ѹ��ô��Ǯ��С�����ⲻ��\n");
                money=money_ob->query("base_unit")+money_ob->query("name");
                i=money_ob->value()-bet_amt;
                destruct(money_ob);
                if (i>0)
                        pay_him(me,i);
                else
                if (i<0)
                        say(BOLD "��������ӵ�������ֻ�ֳ�����"+me->name(1)+"�������ϵ�Ǯ̫���ˣ������Ұ��㱣�ܰɡ�\n" NOR);
        if((int) me->query_temp("gamble/amount")) { 
                if(bet_type != (int) me->query_temp("gamble/type"))
                        return notify_fail("�㲻����һ�����²�ͬ��ע��\n");
                if(bet_type == 0)
                        message = sprintf(RED"С"NOR);
                if(bet_type == 1)
                        message = sprintf(RED"��"NOR);
                if(bet_type == 2)
                        message = sprintf(RED"Χ��"NOR);
                if(bet_type >=3)
                        message = sprintf(RED"%s"NOR,chinese_number(bet_type));
                    message_vision(sprintf("$N�ִ������ó�%s%s����ѹ��%s�ϣ�\n",
                                chinese_number(amount), money,message), me);
                bet_amt += (int) me->query_temp("gamble/amount");
            me->set_temp("gamble/amount",bet_amt);
        }
        else
        {
                if(bet_type == 0)       
                        message = sprintf(RED"С"NOR);
                if(bet_type == 1)
                        message = sprintf(RED"��"NOR);
                if(bet_type == 2)
                        message = sprintf(RED"Χ��"NOR);
                if(bet_type >=3)
                        message = sprintf(RED"%s"NOR,chinese_number(bet_type));
                message_vision(sprintf("$N�������ó�%s%s��ѹ��%s�ϣ�\n",
                                        chinese_number(amount),money, message), me);
                me->set_temp("gamble/type",bet_type);
                me->set_temp("gamble/amount",bet_amt);
        }
        stat[bet_type] += bet_amt;
        if( find_call_out("rolldice") == -1)
                call_out("rolldice",30);
        if( find_call_out("rolldice") >10 && find_call_out("advertise") == -1)
                call_out("advertise",random(5)+1);
        return 1;
}

void advertise()
{
        switch( random(3) ) {
                case 0: message_vision("$N����Ц��������ע����ע��һ����Ӯ��\n",this_object());
                        break;
                case 1: message_vision("$N˵�����ٲ���ע���������ˣ�\n",this_object());
                        break;
                case 2: message_vision("$N�����⣬�����Ŵ�ң��ӣ��ټӴ���Ķ�ע��һ��Ӯ��\n",this_object());
                        break;
        }
        if( find_call_out("rolldice") >=10)
                call_out("advertise",random(4)+5);
	return;
}

void rolldice()
{
        this_object()->set("too_late",1);
        message_vision("$N�����е����¶�ע��˵�գ������е����������������\n",this_object());
        message_vision("\n������������������������ţ������ö�������������\n",this_object());
        call_out("first_dice",3);
	return;
}

void first_dice()
{
        int first;
        this_object()->set("first_dice",(random(1000)%18)/3);
        switch( random(3) ) {
                case 0:
        message_vision("\nһ�����ӵ��˼��£�ͣ�ڣ�\n\n",this_object());
                        break;
                case 1:
        message_vision("\nһ�����ӣ����������������˼��£�������ͣ��������\n\n",this_object());
                        break;
                case 2:
        message_vision("\n���������໥һײ��һ��ֱ����ף�\n\n",this_object());
                        break;
        }
        first = (int) this_object()->query("first_dice");
        message_vision(dice[first], this_object());
        this_object()->set("first_dice",first+1);
        call_out("second_dice",4);
	return;
}

void second_dice()
{
        int second;
       	this_object()->set("second_dice",(random(1000)%18)/3);
        if (this_object()->query("first_dice")+1 ==this_object()->query("second_dice") )
        	this_object()->set("second_dice",(random(1000)%18)/3);
        switch( random(3) ) {
                case 0: message_vision("\n��һ�����ӻ�����ͣ��������\n\n",this_object());
                        break;
                case 1: message_vision("\n�ڶ��������������ת��ͣ�������ط��˸���\n\n",this_object());
                        break;
                case 2: message_vision("\n���������໥һײ������һ������һ����\n\n",this_object());
                        break;
        }
        second= (int) this_object()->query("second_dice");
        message_vision(dice[second], this_object());
        this_object()->set("second_dice",second+1);
        call_out("third_dice",5);
	return;
}
void third_dice()
{
        int third;
       	this_object()->set("third_dice",(random(1000)%18)/3);
        if (this_object()->query("third_dice")+1 ==this_object()->query("second_dice") )
        	this_object()->set("third_dice",(random(1000)%18)/3);
        if (this_object()->query("third_dice")+1 ==this_object()->query("first_dice") )
        	this_object()->set("third_dice",(random(1000)%18)/3);
        switch( random(3) ) {
                case 0:
       message_vision("\n���һ�����������ﻬ�����£�����ͣ�ڣ�\n\n",this_object());
                        break;
                case 1:
        message_vision("\n�������һ�����������޵�ת����ͣ�������ڣ�\n\n",this_object());
                        break;
                case 2:
        message_vision("\n���һ������Ҳ����ͣ���ˣ�\n\n",this_object());
                        break;
        }
        third= (int) this_object()->query("third_dice");
        message_vision(dice[third], this_object());
        this_object()->set("third_dice",third+1);
        call_out("end_the_round",2);
	return;
}
void end_the_round()
{
        int tot,reward,i,first, second, third,j;
        object *inv;
        first = (int) this_object()->query("first_dice");
        second= (int) this_object()->query("second_dice");
        third = (int) this_object()->query("third_dice");
// announce results:
	message_vision(sprintf("\n$N�����е���%s��%s��%s��",
                chinese_number(first),chinese_number(second),chinese_number(third)),
                this_object());
// see who is the winner!
     	if (!first || !second || !third){
       		tot = first+second+third;
      		message_vision(sprintf("%s....�㣬��?������ˤ���ˣ�������˼����Сͨ��!\n",chinese_number(tot)),this_object());
		inv = deep_inventory(environment(this_object()));
        	for(i=0; i<sizeof(inv); i++) {
        		if( inv[i] && userp(inv[i]) && (int) inv[i]->query_temp("gamble/amount") )
        		{
                		inv[i]->set_temp("gamble/amount",0);
        		}
        	}
	}else
	if( second == first && third == first)
	{
	message_vision("��Сͨ�ԣ���\n",this_object());
	inv = deep_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
        	if( inv[i] && userp(inv[i]) && (int) inv[i]->query_temp("gamble/amount") )
        	{
                	if((int) inv[i]->query_temp("gamble/type") == 2)
                	{
                		message_vision("Ӯ�ң�$N��һ����ʮ������\n",inv[i]);
                                reward = (int) inv[i]->query_temp("gamble/amount");
                                for (j=0; j<=36;j++)
                      			pay_him( inv[i],reward);
                	}
                	inv[i]->set_temp("gamble/amount",0);
        	}
        }
	}else{
		tot = first+second+third;
		message_vision(sprintf("%s�㣬",chinese_number(tot)),this_object());
		if( tot>10 )
			message_vision("����С��\n",this_object());
		else
			message_vision("��С�Դ�\n",this_object());
	inv = deep_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
        if( inv[i] && userp(inv[i]) && (int) inv[i]->query_temp("gamble/amount") )
        {
                if((int) inv[i]->query_temp("gamble/type") == tot)
                {
                message_vision("Ӯ�ң�$N��һ���ģ�\n",inv[i]);
                                reward = (int) inv[i]->query_temp("gamble/amount");
                                for (j=0; j<=4;j++)
                      pay_him( inv[i],reward);
                inv[i]->set_temp("gamble/amount",0);
                }
                else 
                if(((int) inv[i]->query_temp("gamble/type") == 0 && tot <=10 ) ||
                        ((int) inv[i]->query_temp("gamble/type") == 1 && tot > 10 ))
                {
                message_vision("Ӯ�ң�$N��һ��һ��\n",inv[i]);
                                reward = (int) inv[i]->query_temp("gamble/amount");
                                for (j=0; j<=1;j++)
                      pay_him( inv[i],reward);
                inv[i]->set_temp("gamble/amount",0);
                }
                else
                {
// here are the losers
                reward = (int) inv[i]->query_temp("gamble/amount");
                // inv[i]->decrease_skill("betting", reward, 1);
                inv[i]->set_temp("gamble/amount",0);
                }
        }
        }
	}
	this_object()->set("too_late",0);
	this_object()->set("first_dice",0);
	this_object()->set("second_dice",0);
	this_object()->set("third_dice",0);
	clear_stat();
	return;
}
void pay_him(object who, int amount)
{
        object ob;
        if( amount < 0 ){
            say(BOLD "��������ӵ�������ֻ�ֳ�����"+who->name(1)+"�������ϵ�Ǯ̫���ˣ������Ұ��㱣�ܰɡ�\n" NOR);
            return;
        }
		if (environment(who)!=environment(this_object()))     return;
        if( amount/10000000 ) {
               ob = new(THGOLD_OB);
               ob->set_amount(amount/10000000);
               if ( !ob->move(who) )
                     ob->move(environment(who));
                amount %= 10000000;
        }
        if( amount/100000 ) {
               ob = new(THCASH_OB);
               ob->set_amount(amount/100000);
               if ( !ob->move(who) )
                     ob->move(environment(who));
                amount %= 100000;
        }
        if( amount/10000 ) {
               ob = new(GOLD_OB);
               ob->set_amount(amount/10000);
               if ( !ob->move(who) )
                     ob->move(environment(who));
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                if (!ob->move(who))
                     ob->move(environment(who));
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                if (!ob->move(who))
                     ob->move(environment(who));
        }
}
int accept_object(object who, object ob)
{
        int bet_type;
        string message;
        
                if( ob->value() >= 100) {
                        say("��ʥ�Ǻǵ�Ц����л��...\n");
        message_vision("$N��$n�����ֹ��˼��䣮��\n",this_object(),who);
        bet_type = random(1000)%19;
        if(bet_type == 0)
                message = sprintf(RED"С"NOR);
        if(bet_type == 1)
                message = sprintf(RED"��"NOR);
        if(bet_type == 2)
                message = sprintf(RED"Χ��"NOR);
        if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));
        tell_object(who,"��ʥ���ĸ����㣺���ֶ�ѹ"+message+"��һ��Ӯ��\n");
        message_vision("$N���ĵ�΢Ц��������\n",who);
        
                        return 1;
                } else {
                    say("��ʥ˵�������Ǯ�㻹���Լ��ðɣ�\n");
                        return 0;
                }
        return 0;
}
void clear_stat()
{
        int i;
        for(i=0;i<=18;i++)
                stat[i]=0;
}
void die()
{
 foreach (object user in deep_inventory(environment(this_object()))){
        if( user && userp(user))
        {
          user->delete_temp("gamble");
        }
 }
  ::die();
}

