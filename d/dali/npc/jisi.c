// jisi.c

inherit NPC;

void create()
{
	set_name("��˾", ({ "ji si", "si" }));
	set("age", 62);
	set("gender", "Ů��");
	set("long", "һλ�������Ƶ����긾Ů���Ǳ���Ĵ��˾������˾�ؼ�̨��̨��ʱ��ĸϵ���壬��˾Ҫְ��Ϊ��Ů��\n");
	set("attitude", "peaceful");

	set("str", 20);
	set("per", 12);
	set("dex", 16);
	set("combat_exp", 40000);
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
