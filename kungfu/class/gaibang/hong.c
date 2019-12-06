// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "��ָ��ؤ");
	set("gender", "����");
	set("age", 75);
	set("long", 
		"������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_msg", ({
		"���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
		"���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
		"���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
//		(: random_move :),
	}));
//	set("inquiry", ([
//		"������" : "����������������\n",
//		"ؤ��" : "����������������\n",
//		"��ʦ" : "�����ȥ�����ŵ��Ұ��ܶ��³�нš�\n",
//	]));

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);
	
	set("combat_exp", 1000000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 200);             // �����ڹ�
	set_skill("huntian-qigong", 200);    // ��������
	set_skill("unarmed", 200);           // ����ȭ��
	set_skill("xianglong-zhang", 200);   // ����ʮ����
	set_skill("dodge", 200);      	     // ��������
	set_skill("xiaoyaoyou", 200);        // ��ң��
	set_skill("parry", 200);             // �����м�
	set_skill("staff", 200);             // ��������
	set_skill("dagou-bang", 200);        // �򹷰���
	set_skill("begging", 100);           // �л�����
	set_skill("checking", 100);          // ����;˵
	set_skill("training", 100);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	
	create_family("ؤ��", 17, "����");
	setup();
	
       carry_object(__DIR__"obj/beggar-cloth")->wear();
    carry_object(__DIR__"obj/yuzhu_zhang")->wield();
    carry_object(__DIR__"obj/jiaohuaji");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
		command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
		return;
	}
//	if ((string)ob->query("family/family_name") != "" &&
//	    (string)ob->query("family/family_name") != "ؤ��") {
//		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");
//		return;
//	}
	if (this_player()->query_temp("jiahuoji")) command("recruit " + ob->query("id"));
        else
	command("say " + RANK_D->query_respect(ob) + "��������������ֻ��ϧ�Ͻл�����û������ͽ����");
	
}

int accept_object(object who, object ob)
{
	if (ob->query("food_supply") <= 0)
		return 0;
	if ((string)ob->query("id") != "jiaohua ji") {
		command("say �Ͻл���" + (string)ob->query("name") + "ûʲô��Ȥ����");
		return 0;
	}
	if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
		command("say �Ͻл����ڱ��úܡ�");
		return 0;
	}
	command("say ����������������ԵĽл���ѽ��");
	command("eat ji");
	who->set_temp("jiahuoji",1);
	return 1;
}
