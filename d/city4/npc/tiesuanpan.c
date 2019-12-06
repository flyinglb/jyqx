// tiesuanpan.c
 
inherit NPC;
inherit F_BANKER;

void reset_balance(object  me);

void create()
{
        set_name("������",  ({"tie suanpan",  "tie",  "zhanggui"}));
        set("title",  "Ǯׯ�ƹ�");
        set("no_beg_from", 1);
        set("no_get_from", 1);
        set("no_steal_from", 1);

        set("gender",  "����");
        set("age",  54);
        set("qi",  800);  
        set("max_qi",  800);
        set("jing",  200);
        set("max_jing",  200);
        set("combat_exp",  50000);
        set("attitude",  "friendly");
        set("env/wimpy",  50);
        set("chat_chance",  10);
        set_skill("unarmed",  60);
        set_skill("parry",  60);
        set_skill("dodge",  60);

        setup();
        carry_object(__DIR__"obj/choupao")->wear();
        add_money("gold",  1);
}
/*
void  init()
{
        call_out("reset_balance",  1,  this_player());
        ::init();
}

void  reset_balance(object  me)
{
        int  myexp;
        int  allowed,  removed_gold;
        string  myid;
        string  NPCNAME=this_object()->name();

        if(!me)  return;

        myexp=me->query("combat_exp")/1000;
        myid=me->query("id");

        if(myexp<1)  myexp=1;
        if(myexp>100)  myexp=100;
        allowed=myexp*1000000;//each  year  can  have  100  gold,  range  100-10000.  
        if  (me->query("balance")  >  allowed)
        {
	me->set("balance_old",  me->query("balance"));
	me->set("balance",  allowed);
	removed_gold  =  (me->query("balance_old")  -  me->query("balance"))/10000;
	log_file("MONEY_RESET",  ctime(  time()  )+"��κ�����ս���"+me->query("name")+"("+me->query("id")+")"+removed_gold+"���ƽ�\n");
	tell_object(me,  GRN+NPCNAME+"����Ķ�������˵����"+RANK_D->query_respect(me)+
		"���⡢���治֪��ô˵�Ǻã�����\n"NOR);
	tell_object(me,  GRN+NPCNAME+"����Ķ�������˵����"+
		"����κ��������ǰ���참���������ϵĻƽ���·������\n"NOR);
	tell_object(me,  GRN+NPCNAME+"����Ķ�������˵����"+
		"���������°����ϱ�⣬���ϵ�Ǯ��ȫ���乫�ˣ�����\n"NOR);
        }
        return;
}
*/
void accept_fight(object me)
{
        object  ob;
        if(is_fighting())  return;
        if(  query("called")  )  return;

        command("help!");
        ob=present("wu jiang");
        if(  !ob)  {
                seteuid(getuid());
                ob=new("/d/city/npc/wujiang");
                ob->move(environment());
        }
        message_vision("\n��Ȼ������������Ѳ���佫����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called",  1);
        call_out("regenerate",  300);
}
int  regenerate()
{
        set("called",  0);
        return  1;
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
        delete_temp("busy");
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
        if (!total || total < 0)
        {
                this_player()->set("balance", 0);
                return notify_fail("���ڱ��̺�û�д�Ǯ��\n");
        }
        write("���������ĸ����㣺���ڱ��̺Ź�����" + 
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
        if (bv1 < bv2)  amount -= amount % (bv2 / bv1);
        if (amount == 0)
        {
           return notify_fail("��Щ" + from_ob->query("name") + "��������\n ");
        }

        // allowed to convert now
        set_temp("busy", 1);

        from_ob->add_amount(-amount);

        if (!to_ob)
        {
                to_ob = new("/clone/money/" + to);
                to_ob->set_amount(amount * bv1 / bv2);
                to_ob->move(me);
        }
        else
                to_ob->add_amount(amount * bv1 / bv2);

        message_vision(sprintf("$N������ȡ��%s%s%s��������%s%s%s��\n",
        chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
        chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"),
        to_ob->query("name")), me);

//      from_ob->add_amount(-amount);

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
        if(amount >= 100)
        {
                return notify_fail("��ô�����Ŀ������û��ô����ɢ�ֽ�\n");
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
        MONEY_D->pay_player(me, v = v * 9 / 10);

        message_vision(sprintf("$N��������ȡ��%s��\n", MONEY_D->money_str(v)), me);

        remove_call_out("enough_rest");
        call_out("enough_rest", 5);
        return 1;
}
*/
