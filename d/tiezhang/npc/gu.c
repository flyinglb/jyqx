// gu.c ������
// by pishou and zqb :)

inherit NPC;
//inherit F_SKILL;
int ask_wumu();
int ask_yishu();
int ask_jiannan();
void create()
{
    set_name("������", ({ "gu yanwu", "gu" }));
    set("long", "�����������䣬��ͤ�֣�������ɽ��ʿ��\n" "�������ǵ������壬����֮�����˹��䣬���Ӳ��ˡ�\n" "���ָ����ݣ���Ŀ��ڡ�\n");
	set("gender", "����");
    set("age", 55);

    set_skill("literate", 200);

    set_temp("apply/attack", 10);
    set_temp("apply/defense", 10);
    set_temp("apply/damage", 5);

    set("combat_exp", 500);
	set("shen_type", 1);
	setup();

        set("inquiry", ([
                "��" : "���Ƕ�հ�����ĵ��ࡣ",
              "��հ" : "�����ǵ���һλ�󻭼ҡ�",
            "��ʿ��" : "��հ������λ�����������ǣ�����ⳡ����ʷ�����С�",
              "���" : "�����, Ҳ���ǲ����, �������������, ���ﲻ����", 
              "����" : "���������˹㶫�ᶽ�����潫����",
            "������" : "�����潫�����ڲ�Ӫ���ں�, ʵ��������ػ��˳��������",
            "��ػ�" : "��ػ���̨�����ү��ƽ����֣�ɹ�����ı��������������",
            "������" : "�����������������ֵܣ��ؿ����̰��ֱ��ǻ���Ŀںš�",
              "�ں�" : "��ظ�ĸ�����帴����",
          "���帴��" : "��ҲҪѧһѧ���������¾��ұ���, �����Ծ�����? ",
          "������" : (: ask_wumu :),
          "��������" : (: ask_yishu :),
          "�Ϲٽ���" : (: ask_jiannan :),
        ]) );
	set("chat_chance", 3);
	set("chat_msg", ({
        "����������ʵ��������ϸ�Ѵ��ң����ºγ������ˣ� ���Ǿ����� \n",
        "�����������˽�ɽ�������ĵҡ��ұ�����������͵����䣬ʵ���˱������ߡ�\n",
        "�������������һ��������²�����Ҵ󺺺�ɽ����֮ͽ�㱯�ߣ�����������׳��\n",
        "�������������֮������������Դ����������Ҳ���ܶ�������ȥ����������\n",
	}) );
}

int ask_wumu()
{
command("say ���������������٣��˿����������һ���ñ����񡣾�˵������������һ��\n"
"�������飬���м�������һ���������ĵı���Ҫ����\n");
return 1;
}

int ask_yishu()
{
command("say �ⲿ���������ղ��ڻʹ�֮�У�����˵���ư�����Ϲٽ����ʰ��и��֣���\n"
"����͵�ߣ���֪�����Ǽ١�\n");
return 1;
}

int ask_jiannan()
{
        object zitie, me, ob;

        me = this_object();
        ob = this_player();
        
	zitie = new("/d/tiezhang/obj/zitie");
        if ( present("zitie", ob) )
	{
		command("say �Ҳ����Ѿ���������ô����ô���ʣ�\n");
		return 1;
	}

command("say ��λ�Ϲٰ�������һλ����֮ʿ�����ư��������κ��������٣�������\n"
"��֮�£������������ƴ����ڽ�������Ѱ�ѿ����뱱����ؤ���ͥ�����ˡ�ֻ�Ǻ�����\n"
"Ȼ�����伣����֪�����ˡ��������ҵ��������飬�����ҵ��Ϲٰ������У�\n");
command("look " + ob->query("id"));
command("say ����" + RANK_D->query_respect(ob) + "Ҳ���ұ����ˣ�����������һ�������͸��㣬ϣ����\n"
"�ܲ���������²�����Һ�ɽ��־��");
zitie->move(ob);
message_vision("$N����$nһ��������\n", me, ob);
return 1;
}

int recognize_apprentice(object ob)
{
	int money=50, level = ob->query_skill("literate", 1);

	if (level>29) money=100;
	if (level>59) money=500;
	if (level>89) money=1000;
	if (level>119) money=5000;

    ob->delete_temp("mark/��");
	switch(MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2:
			write("�����ڵ�ѧ����ÿ��" + MONEY_D->money_str(money) + "���뱸����Ǯ��\n");
			return 1;
	}
    ob->set_temp("mark/��", 1);
	return 1;
}
/*
int accept_object(object who, object ob)
{
	int money=25, level = who->query_skill("literate", 1);

	while (level >= 0) {
		money += money;
		level -= 30;
	}

	if (ob->query("money_id")) {
		if (ob->value() >= money) {
            if ((int)who->query_temp("mark/��") < 1)
                who->set_temp("mark/��", 1);
            message_vision("������ͬ��ָ��$NһЩ�����徭�����⡣\n", who);
            who->add_temp("mark/��", ob->value() / money);
			return 1;
		}
		return notify_fail("�����ڵ�ѧ����ÿ��" + MONEY_D->money_str(money) + "��\n");
	}
	return 0;
}
*/

