//menwei.c
inherit NPC;

void greeting(object);
void init();
void create()
{
	set_name("����", ({ "men wei", "wei"}) );
	set("nickname", "��ʨ��");
	set("gender", "����" );
	set("age", 22);
	set("long", "���Ǹ��긻��ǿ������������ʮ�����ϡ�\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("combat_exp", 9000+random(1000));
	set("score", 12000);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 30+random(10));
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor",20);

	setup();
	add_money("silver",20);
	carry_object("/d/baituo/obj/dadao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if((string)ob->query("family/family_name")=="����ɽ��")
	   { say("����Ц������˵������λ" + RANK_D->query_respect(ob)
	     + "�������ˣ�������ɡ���\n");
	     return;
	    }
	if(!ob->query("family/family_name"))
	   { say("��������Ц�ݵ�˵������λ" + RANK_D->query_respect(ob)
	     + "��������ʦ�İɡ�\nʦ���������棬������ɡ�\n");
	     return;
	    }
	if((int)ob->query("shen")>200)
	   { say("��������һ�ɣ�˵������λ" + RANK_D->query_respect(ob)
	     + "���������鷳�İɡ�\n��Ȱ�㲻Ҫ���������\n");
	     return;
	    }
}
