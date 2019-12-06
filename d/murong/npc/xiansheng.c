// xiansheng.c ��������
inherit NPC;

void create()
{
	set_name("��������", ({ "teacher" , "xiansheng" }));
	set("long", "������Ľ�ݼ������Ľ���������\n");
	set("gender", "����");
	set("age", 65);

	set_skill("literate", 300);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);

	set("combat_exp", 500000);
	set("shen_type", 1);
	setup();

	set("chat_chance", 3);
	
}

int recognize_apprentice(object ob)
{
	int money=50, level = ob->query_skill("literate", 1);

	if (level>29) money=100;
	if (level>59) money=500;
	if (level>89) money=1000;
	if (level>119) money=5000;
	       if (!(int)ob->query_temp("mark/��ʦ"))
               return 0;
        ob->add_temp("mark/��ʦ", -1);
        return 1;
	/*ob->delete_temp("mark/��");
	switch(MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2:
			write("�����ڵ�ѧ����ÿ��" + MONEY_D->money_str(money) + "���뱸����Ǯ��\n");
			return 1;
	}
	ob->set_temp("mark/��", 1);
	return 1;*/
}
int accept_object(object who, object ob)
{
	int money=25, level = who->query_skill("literate", 1);

	while (level >= 0) {
		money += money;
		level -= 30;
	}

	if (ob->query("money_id")) {
		if (ob->value() >= money) {
			if ((int)who->query_temp("mark/��ʦ") < 1)
				who->set_temp("mark/��ʦ", 1);
message_vision("˽������ͬ��ָ��$NһЩ����д�ֵ����⡣\n", who);
			who->add_temp("mark/��ʦ", ob->value() / money);
			if( who->query_skill("literate", 1) > 121){
        tell_object(who,"����������һ�����Ļ�֪ʶ,Ҳ�����Լ����������ˡ�\n");
        return 1;
		}
		return notify_fail("�����ڵ�ѧ����ÿ��" + MONEY_D->money_str(money) + "��\n");
	}
		return 1;}
return 1;
}

