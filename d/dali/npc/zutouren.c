// zutouren.c

inherit NPC;

void create()
{
	set_name("��ͷ��", ({ "zu touren", "touren" }));
	set("age", 42);
	set("gender", "����");
	set("long", "��λ�ǹ������ͷ�ˣ������Ǵ�����ĵ������壬�����ڴ�
����������ò�����������Խ��£����ǰײ���ͷ�������ڴ���˾��
�����ף�������ϸϸ�����š�\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("per", 20);
	set("dex", 36);
	set("combat_exp", 100000);
	set("shen_type", 1);

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 70);
	set_temp("apply/armor", 70);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
