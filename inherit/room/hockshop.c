// hockshop.c

inherit ROOM;

void init()
{
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
	add_action("do_sell", "sell");
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "��Ǯ";
	else
		return chinese_number(value/100) + "��"
			+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
}

void pay_player(object who, int amount)
{
	object ob;

	if( amount < 1 ) amount = 1;
	if( amount/100 ) {
		ob = new(SILVER_OB);
		ob->set_amount(amount/100);
		ob->move(who);
		amount %= 100;
	}
	if( amount ) {
		ob = new(COIN_OB);
		ob->set_amount(amount);
		ob->move(who);
	}
}

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ��ʲô��Ʒ�����̹��ۣ�\n");

	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");

	value = ob->query("value");
	if( !value ) printf("%sһ�Ĳ�ֵ��\n", ob->query("name"));
	else 
		printf("%s��ֵ%s��\n�����Ҫ�䵱(pawn)�������õ�%s��һ�ŵ�Ʊ��\n�������(sell)�������õ�%s��\n",
			ob->query("name"), value_string(value),
			value_string(value * 60 / 100), value_string(value * 80 / 100));

	return 1;
}

int do_pawn(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ�䵱ʲô��Ʒ��\n");

	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");

	value = ob->query("value");
	if( !value ) return notify_fail("����������ֵǮ��\n");

	message_vision("$N�����ϵ�" + ob->query("name") + "�ó����䵱��"
		+ value_string(value * 60 / 100) + "��\n", this_player());

	pay_player(this_player(), value * 60 / 100);
	destruct(ob);

	return 1;
}

int do_sell(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ����ʲô��Ʒ��\n");

	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");
	value = ob->query("value");
	if( !value ) return notify_fail("����������ֵǮ��\n");


	message_vision("$N�����ϵ�" + ob->query("name") + "������\n",
		this_player());

	pay_player(this_player(), value * 80 / 100);
	destruct(ob);

	return 1;
}

