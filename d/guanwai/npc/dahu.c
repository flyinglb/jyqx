// dahu.c

inherit NPC;

void create()
{
	set_name("���״�", ({ "da hu" }));
	set("gender", "����");
	set("nickname", "����");
	set("age", 19);
	set("long", "����һ�����޾��ˣ��ֽŴִ��������ˣ�ȴ���Դ��ӡ�\n");
	
	set("combat_exp", 100000);
	set("shen_type", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}
