// shi.c ʷ��ɽ

inherit NPC;

void create()
{
	set_name("ʷ��ɽ", ({ "shi qingshan", "shi" }));
	set("title", "�����ؽ�");
	set("gender", "����");
	set("age", 33);
	set("str", 25);
	set("dex", 16);
	set("long", "ʷ��ɽ�������䵱ɽ���׼ҵ��ӣ���֪Ϊ�γ����˳�͢����\n");
	set("combat_exp", 200000);
	set("shen_type", 1);
	set("attitude", "heroism");

	set_skill("unarmed", 70);
	set_skill("force", 70);
	set_skill("sword", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("taiji-jian", 50);
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 20);

	set("max_qi", 700);
	set("neili", 700); 
	set("max_neili", 700);
	set("jiali", 20);

	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/tiejia")->wear();
}

int accept_fight(object me)
{
	command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������");
	return 0;
}
