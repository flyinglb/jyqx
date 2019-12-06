// wokou.c

inherit NPC;

void create()
{
	set_name("����", ({ "wo kou", "wo", "kou"}));
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "�������쳯����̨����ձ����ˣ�����ͨ����ʿ�����쳯��֮���ܡ�\n");
	set("combat_exp", 30000);
	set("shen_type", 1);
	set("attitude", "aggressive");

	set_temp("apply/attack", 35);
	set_temp("apply/defense", 35);
	set_temp("apply/armor", 35);
	set_temp("apply/damage", 35);
	set_skill("blade", 35);
	set_skill("dodge", 35);

	setup();
	carry_object(__DIR__"obj/wodao")->wield();
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
	if( environment(ob) != environment() ) return;
	say("����̧�۴�ŭ��������������˸���·����ģ���˵̨�������ǵģ����������ģ�\n");
}

