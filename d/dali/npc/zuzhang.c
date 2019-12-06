// zuzhang.c

inherit NPC;

void create()
{
	set_name("�峤", ({ "zu zhang", "zhang" }));
	set("age", 62);
	set("gender", "Ů��");
	set("long", "һλ�������Ƶ����긾Ů�����Ǳ�����峤��̨��ʱ��ĸϵ���壬����Ȩ���Ϊ��Ů��\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("per", 12);
	set("dex", 16);
	set("combat_exp", 30000);
	set("shen_type", 1);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("blade", 20);
	set_skill("force", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	setup();
	carry_object(__DIR__"obj/tongqun")->wear();
}
