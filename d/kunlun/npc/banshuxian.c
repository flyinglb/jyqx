inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�����", ({ "ban shuxian", "ban", "shuxian"}) );
        set("title", HIG "���������ŷ���" NOR);
        set("gender", "Ů��");
        set("age", 38);
        set("long",
         "���������������ź�̫������ӡ���Ƣ���ֱ���������խ
�������¶�����ʮ��η�塣������ʮ���ˣ����Ƿ����ȴ档\n");        
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 35);
        set("con", 50);
        set("per", 28);
        set("dex", 80);
        set("jingli",1000);
        set("max_jingli",1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali",200);
        set("rank_info/respect", "���ŷ���");        
        set("combat_exp",1000000);
 
	set_skill("force", 190);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("xuantian-force", 180);
	set_skill("sword", 200);
	set_skill("literate",100);
	set_skill("zhengliangyi-sword", 190);
	set_skill("yaoming-dodge", 200);
	set_skill("sanyin-unarmed",170);
	set_skill("unarmed",200);
           
	map_skill("dodge", "yaoming-dodge");
	map_skill("force", "xuantian-force");
	map_skill("parry", "zhengliangyi-sword");
	map_skill("sword", "zhengliangyi-sword");
	map_skill("unarmed","sanyin-unarmed");   
	prepare_skill("unarmed","sanyin-unarmed"); 

	create_family("������", 4, "���ŷ���");
	setup();
	carry_object("/clone/cloth/female4-cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "Ů��" )
	{        
		command("say ���˶����Ǻö��������ҹ���");
		return;
	}

	if ((int)ob->query_skill("xuantian-force", 1) < 50) 
	{
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������ڹ��ķ���");
		return;
	}

	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
        ob->set("class", "swordsman");
	ob->set("title", HIG "�����ɵ��������" NOR);
}
