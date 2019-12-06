// youfangdaoren.c
// Date: YZC 96/01/19

inherit NPC;

void create()
{
	set_name("�η�����", ({"youfang daoren","daoren"}));
	set("long",
		"����һλδͨ���ʵ�������ˣ����Ϲ��ź������΢Ц��\n"
	);

	set("gender", "����");
	set("attitude", "heroism");
	set("class", "taoist");

	set("age", 20);
	set("shen_type", 1);
	set("str", 15);
	set("int", 30);
	set("con", 30);
	set("dex", 18);
	set("max_qi", 280);
	set("max_jing", 300);
	set("neili", 380);
	set("max_neili", 380);
	set("jiali", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("chat_chance", 30);

	set("chat_msg", ({
		"�η�����˵��: ����λʩ�����������Ӹ�ƶ������ϲ��ϲ���츣������\n",
		(: random_move :)
	}) );

	set_skill("force", 41);
	set_skill("strike", 41);
	set_skill("dodge", 41);
	set_skill("parry", 41);
	set_skill("jinyan-gong", 42);
	set_skill("haotian-zhang", 41);
	set_skill("xiantian-qigong", 41);

	map_skill("force", "xiantian-qigong");
	map_skill("dodge", "jinyan-gong");
	map_skill("strike", "haotian-zhang");
	map_skill("parry", "haotian-zhang");
        create_family("ȫ���", 4, "����");
	setup();
	carry_object("/d/city/obj/cloth")->wear();

	setup();

}

int accept_object(object me, object ob)
{
	object ling;
	
	command("smile");
	command("say �����ٷ𣬶�л��λ" + RANK_D->query_respect(me) + " ��");

	if( ob->query("money_id") && ob->value() >= 10000 && me->query("class") != "bonze" ) 
	{
		command("say " + RANK_D->query_respect(me) + 
		"������ƺ�ʩ�����������գ�ȫ����ʦ����һ�����º��ܣ���֪��Ը����������һ�Σ�");

		ling=new("/d/quanzhen/npc/obj/tie-ling");
		ling->move(me);
		message_vision("�η����˸�$Nһ���������ơ�\n", me);

		command("say ������ʱһ�գ���ʱʧЧ��������ʱǰ�빬��������в��㣬�м��мǣ�"); 
		return 1;
	}

	return 1;
}

