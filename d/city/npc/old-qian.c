// banker.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("Ǯ�ۿ�", ({"qian yankai", "qian", "yankai"}));
	set("title", "Ǯׯ�ϰ�");
	set("nickname", "������");
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
	set("chat_chance", 2);
	set("chat_msg", ({
	"Ǯ�ۿ�������˵�����������Ѿ����ϰ������ʷ���ڽ��Ͽ���˵�ǵ�һ�ҡ�\n",
	"Ǯ�ۿ�Ц��˵�����ڱ����Ǯ����Ϣ��ȡǮ��ʮ��֮һ�����ѣ��͹������Ű�ɡ�\n"
	}));

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	add_money("gold", 5);
}

void init()
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
//	add_action("do_convert", "convert");
//	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
}

int do_check(string arg)
{
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");
	
	if (!total || total < 0) {
		this_player()->set("balance", 0);
		return notify_fail("���ڱ��̺�û�д�Ǯ��\n");
	}
	write("Ǯ�ۿ����ĸ����㣺���ڱ��̺Ź�����" + 
		MONEY_D->money_str(total) + "\n");

	return 1;
}

/*int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
		return notify_fail("�����ʽ��convert|duihuan <����> <���ҵ�λ> to <�»��ҵ�λ>\n");

	from_ob = present(from + "_money", this_player());
	to_ob = present(to + "_money", this_player());

	if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
		return notify_fail("����һ���ʲô��\n");
	if (!from_ob)
		return notify_fail("������û�д�����Ǯ��\n");
	if (amount < 1)
		return notify_fail("�����׬����\n");
	if ((int)from_ob->query_amount() < amount)
		return notify_fail("�����" + from_ob->query("name") + "������\n");
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
		return notify_fail("����������ֵǮ��\n");

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	
	if (amount == 0)
		return notify_fail("��Щ" + from_ob->query("name") + "��������\n");

	// allowed to convert now
	if (!to_ob) {
		to_ob = new("/clone/money/" + to);
		to_ob->move(this_player());
		to_ob->set_amount(amount * bv1 / bv2);
	}
	else
		to_ob->add_amount(amount * bv1 / bv2);
	
	message_vision(sprintf("$N������ȡ��%s%s%s��������%s%s%s��\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
	to_ob->query("name")), this_player());

	from_ob->add_amount(-amount);
	return 1;
}*/

int do_deposit(string arg)
{
	string what;
	int amount;
	object what_ob;

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("�����ʽ��deposit:cun <����> <���ҵ�λ>\n");

	what_ob = present(what + "_money", this_player());
	if (!what_ob)
		return notify_fail("������û�д�����Ǯ��\n");
	if (amount < 1)
		return notify_fail("��������" + what_ob->query("name") + "��\n");
	if ((int)what_ob->query_amount() < amount)
		return notify_fail("�����" + what_ob->query("name") + "������\n");

	// deposit it
	this_player()->add("balance", what_ob->query("base_value") * amount);
	what_ob->add_amount(-amount);
	message_vision(sprintf("$N�ó�%s%s%s����������š�\n", 
	chinese_number(amount), what_ob->query("base_unit"), 
	what_ob->query("name")), this_player());

	return 1;
}

int do_withdraw(string arg)
{
	int amount, v;
	string what;
	
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
		return notify_fail("�����ʽ��withdraw|qu <����> <���ҵ�λ>\n");
	if (amount < 1)
		return notify_fail("����ȡ������Ǯ��\n");
	if (file_size("/clone/money/" + what + ".c") < 0)
		return notify_fail("����ȡ��ʲôǮ��\n");
	what = "/clone/money/" + what;
	if ((v = amount * what->query("base_value")) >
		this_player()->query("balance"))
		return notify_fail("����Ǯ����Ȣ��\n");

	this_player()->add("balance",  -v);
	MONEY_D->pay_player(this_player(), v = v * 9 / 10);
	
	message_vision(sprintf("$N��������ȡ��%s��\n", MONEY_D->money_str(v)),
		this_player());
	return 1;
}
