//trainer.c
inherit NPC;
void greeting(object);
void init();
void create()
{
	set_name("����", ({ "trainer"}) );
	set("gender", "����" );
	set("age", 25);
	set("long", "���Ǹ��Ͱ����׵Ľ�����\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("combat_exp", 30000);
	set("score", 20000);

	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 60);
	set_skill("staff",60);

	create_family("����ɽ��",5,"����");

	setup();
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "����ɽ��")
	 { if(ob->query("qi")<60)
		 message_vision("��������$NЦ���������۰ɣ�û��ϵ���ྡ�����\n",ob);
	   else
		 message_vision("��������$N���������������������ɼΣ�\n",ob);
	  }
}

void attempt_apprentice(object ob)
{
     command("say �Ҳ�����ͽ���㻹�ǰ����ͷ�ɡ�\n");
     return;
}

int accept_fight(object ob)
{
      if ((string)ob->query("family/family_name") == "����ɽ��")
	 {
	  if((int)ob->query("combat_exp")<10000)
	    return notify_fail("����Ц������ľ���̫���ˣ�����������ͯ�ӱȻ��ɣ�(bi tongzi)\n");
	  }
    return 1;
}
