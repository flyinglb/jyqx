// qianlaob.c
#include <ansi.h>

inherit NPC;
inherit F_BANKER;
int ask_weiwang();

void create()
{
	set_name("Ǯ�ϱ�", ({"qian laoben", "qian", "laoben"}));
//	set("title", "Ǯׯ�ϰ�");
	set("title", HIR "��ػ�"HIG"��ľ��"NOR"����");

        set("no_beg_from", 1);
        set("no_get_from", 1);
        set("no_steal_from", 1);

	set("gender", "����");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
	"Ǯ�ϱ�˵�����ҽ�Ǯ�ϱ���������Ϊ���������ϱ�Ҳ���ˡ�\n",
	"Ǯ�ϱ�Ц��˵�����ڱ����Ǯ��Ϣ���ٰٷ�֮һ���͹���ֻ�ܴ�ɡ�\n",
	"Ǯ�ϱ�˵��ֻ�жԱ��ɵ����Ҳ���ô�������Ա���˰����ߺ�......\n",
	"Ǯ�ϱ�ͻȻ˵��: ������������Ҫ������ֵ�ߴ��кô�����\n",
        "Ǯ�ϱ�ͻȻ˵�����˷ֿ�һ��ʫ�����Ϻ�Ӣ����֪��\n",
	}));
        set("inquiry", ([
		"��Ϣ" :  "\n��Ҫ��Ϣ����ᣡ\n",
		"�½���" :  "\n����ܶ�����û��ô���ס�\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"����" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ���ա�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
       ]) );

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 5);
}

void init()
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
//	add_action("do_join","join");
	delete_temp("busy");
}

int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\nǮ�ϱ�˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("Ǯ�ϱ���˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}
/*
void enough_rest()
{
	delete_temp("busy");
}

int do_check()
{
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");
	
	if (!total || total < 0) {
		this_player()->set("balance", 0);
		return notify_fail("���ڱ��̺�û�д�Ǯ��\n");
	}
	write("Ǯ�ϱ����ĸ����㣺���ڱ��̺Ź�����" + 
		MONEY_D->money_str(total) + "\n");

	return 1;
}
int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;
	
	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	{
		return notify_fail("�����ʽ��convert|duihuan <����> <���ҵ�λ> to <�»��ҵ�λ>\n");
	}

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
	{
		return notify_fail("����һ���ʲô��\n");
	}
	if (!from_ob)
	{
		return notify_fail("������û�д�����Ǯ��\n");
	}
	if (amount < 1)
	{
		return notify_fail("�����׬����\n");
	}
	if ((int)from_ob->query_amount() < amount)
	{
		return notify_fail("�����" + from_ob->query("name") + "������\n");
	}
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	{
		return notify_fail("����������ֵǮ��\n");
	}

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	{
		return notify_fail("��Щ" + from_ob->query("name") + "��������\n");
	}

	// allowed to convert now
	set_temp("busy", 1);	

	from_ob->add_amount(-amount);

	if (!to_ob) {
		to_ob = new("/clone/money/" + to);
		to_ob->set_amount(amount * bv1 * 9 / (bv2 * 10));
		to_ob->move(me);
	}
	else
		to_ob->add_amount(amount * bv1 * 9 / (bv2 * 10));
	
	message_vision(sprintf("$N������ȡ��%s%s%s��������%s%s%s��\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 * 9 / (bv2 * 10)), to_ob->query("base_unit"), 
	to_ob->query("name")), me);

//	from_ob->add_amount(-amount);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

	return 1;
}


int do_deposit(string arg)
{
	string what;
	int amount, money_limit;
	object what_ob, me;

	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("�����ʽ��deposit:cun <����> <���ҵ�λ>\n");
	}

	what_ob = present(what + "_money", me);
	if (!what_ob)
	{
		return notify_fail("������û�д�����Ǯ��\n");
	}
	if (amount < 1)
	{
		return notify_fail("��������" + what_ob->query("name") + "��\n");
	}
	if ((int)what_ob->query_amount() < amount)
	{
		return notify_fail("�����" + what_ob->query("name") + "������\n");
	}

	// deposit it
	set_temp("busy", 1);	
	if (me->query("age")==14) money_limit = 100;
	if (me->query("age")>14) money_limit = 100 + (me->query("age")-15) * 20;
	if (me->query("age")>20) money_limit = 200 + (me->query("age")-20) * 20;
	if (me->query("age")>30) money_limit = 400 + (me->query("age")-30) * 30;
	if (me->query("age")>40) money_limit = 800 + (me->query("age")-40) * 40;
	money_limit = money_limit*10000;

	if (me->query("balance") + what_ob->query("base_value") * amount > money_limit)
	{
                return notify_fail("��Ĵ�����Ѿ������ˡ�\n");
	}

	me->add("balance", what_ob->query("base_value") * amount);
	what_ob->add_amount(-amount);
	message_vision(sprintf("$N�ó�%s%s%s����������š�\n", 
	chinese_number(amount), what_ob->query("base_unit"), 
	what_ob->query("name")), me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

return 1;
}
*/
/*
int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me;

	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("�����ʽ��withdraw|qu <����> <���ҵ�λ>\n");
	}
	if (amount < 1)
	{
		return notify_fail("����ȡ������Ǯ��\n");
	}
	if (amount > 210000)
	{
		return notify_fail("�汧Ǹ��С��һʱû��ô���ֽ�\n");
	}
	if (file_size("/clone/money/" + what + ".c") < 0)
	{
		return notify_fail("����ȡ��ʲôǮ��\n");
	}
	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance"))
	{
		return notify_fail("����Ǯ����ȡ��\n");
	}
	
	if(v>30000) 
	{
	if((int)me->query("weiwang")>=50)
	return notify_fail("\nǮ�ϱ�ŭ������Ϊ��ػ���ӣ��㻹����˻ӻ���һ�����ȡ�����ƽ�\n");
	}
	set_temp("busy", 1);	

	me->add("balance",  -v);
	if((int)me->query("weiwang")>=50)
	{
	MONEY_D->pay_player(me, v = v * ((((int)me->query("weiwang")-40)/10)+100)/ 100);
	message_vision(sprintf("$N��������ȡ��%s��\n", MONEY_D->money_str(v)),
		me);
	message_vision("\n$N���ֹ�Ȼ����Ϣ�����˵�����������", me);
        command("goodkid "+this_player()->query("id"));
	}
	else 
	{
	message_vision("\nǮ�ϱ�˵: ���׬�����Բ������ڱ�ׯȡǮû��Ϣ��\n",me); 
	MONEY_D->pay_player(me, v = v * 4/5);
	message_vision(sprintf("$N��������ȡ��%s��\n", MONEY_D->money_str(v)),
		me);
	}
	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
return 1;
}

*/
/*
int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me;

	if (query_temp("busy"))
		return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

	me = this_player();

	if( (int)me->query("balance") > 2000000 )
	{
		me->set("balance",2000000);
		return notify_fail("����ǰ��Ķ���200���ƽ��Ǯ���ٸ�û����.\n");
	}
	
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("�����ʽ��withdraw|qu <����> <���ҵ�λ>\n");
	}
	if(amount >= 100)
	{
		return notify_fail("˵�����Ŀ������û��ô���鷳���֡�\n");
	}
	if (amount < 1)
	{
		return notify_fail("����ȡ������Ǯ��\n");
	}
	if (file_size("/clone/money/" + what + ".c") < 0)
	{
		return notify_fail("����ȡ��ʲôǮ��\n");
	}
	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) > me->query("balance"))
	{
        return notify_fail("����Ǯ����ȡ��\n");
	}

	set_temp("busy", 1);	

	me->add("balance",  -v);
	MONEY_D->pay_player(me, v = v * 8 / 10);
	
	message_vision(sprintf("$N��������ȡ��%s��\n", MONEY_D->money_str(v)),
		me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}
*/
//#include "/kungfu/class/yunlong/tiandihui.h";
