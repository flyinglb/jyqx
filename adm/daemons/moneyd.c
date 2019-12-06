// moneyd.c  Ǯ�Ĺ���

// by Xiang@XKX (95/12/22)
void destroy(object ob)
{
        if(!ob) return;
        ob->move(VOID_OB);
        destruct(ob);
}

string money_str(int amount)
{
    // returns a chinese string of `amount` of money
    string output;

    if (amount / 10000) {
        output = chinese_number(amount / 10000) + "���ƽ�";
        amount %= 10000;
    }
    else
        output = "";
    if (amount / 100) {
        output = output + chinese_number(amount / 100) + "������";
        amount %= 100;
    }
    if (amount)
        return output + chinese_number(amount) + "��ͭ��";
    return output;
}

string price_str(int amount)
{
    // returns a chinese string of `amount` of money
    string output;

    if (amount < 1)
        amount = 1;

    if (amount / 10000) {
        output = chinese_number(amount / 10000) + "���ƽ�";
        amount %= 10000;
    }
    else
        output = "";
    if (amount / 100) {
        if (output != "")
            output += "��" + chinese_number(amount / 100) + "������";
        else
            output = chinese_number(amount / 100) + "������";
        amount %= 100;
    }
    if (amount)
        if (output != "")
            return output + "��" + chinese_number(amount) + "��ͭ��";
        else
            return chinese_number(amount) + "��ͭ��";
    return output;
}

void pay_player(object who, int amount)
{
    int v;
    object ob;

    seteuid(getuid());
    if (amount < 1)
        amount = 1;
    if (v = amount / 10000) {
        ob = new(GOLD_OB);
        ob->set_amount(amount / 10000);
        if( !ob->move(who) ) ob->move(environment(who));
        amount %= 10000;
    }
    if (amount / 100) {
        ob = new(SILVER_OB);
        ob->set_amount(amount / 100);
        if( !ob->move(who) ) ob->move(environment(who));
        amount %= 100;
    }
    if (amount) {
        ob = new(COIN_OB);
        ob->set_amount(amount);
        if( !ob->move(who) ) ob->move(environment(who));
    }
}

int player_pay(object who, int amount)
{
    object g_ob, s_ob, c_ob;
    int gc, sc, cc, left;

    seteuid(getuid());

    if (g_ob = present("gold_money", who))
        gc = g_ob->query_amount();
    else
        gc = 0;
    if (s_ob = present("silver_money", who))
        sc = s_ob->query_amount();
    else
        sc = 0;
    if (c_ob = present("coin_money", who))
        cc = c_ob->query_amount();
    else
        cc = 0;
    //      write(sprintf("gc:%d,sc:%d,cc:%d,amount:%d\n",gc,sc,cc,amount));

    if (cc + sc * 100 + gc * 10000 < amount) 
        if (present("thousand-cash", who))
            return 2;
        else 
            return 0;
    else {
        left = cc + sc * 100 + gc * 10000 - amount;
        gc = left / 10000;
        left = left % 10000;
        sc = left / 100;
        cc = left % 100;

if (!gc && g_ob) destroy(g_ob);
else
        if (g_ob)
            g_ob->set_amount(gc);
        else sc += (gc * 100);
if (!sc && s_ob) destroy(s_ob);
else
        if (s_ob)
            s_ob->set_amount(sc);
        else if (sc) {
            s_ob = new(SILVER_OB);
            s_ob->set_amount(sc);
            if( !s_ob->move(who) ) s_ob->move(environment(who));
        }
if (!cc && c_ob) destroy(c_ob);
else // by rise
        if (c_ob)
            c_ob->set_amount(cc);
        else if (cc) {
            c_ob = new(COIN_OB);
            c_ob->set_amount(cc);
            if( !c_ob->move(who) ) c_ob->move(environment(who));
        }

        return 1;
    }
}
