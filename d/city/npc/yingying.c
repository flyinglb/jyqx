// yingying.c ��ݺݺ

inherit NPC;

void create()
{
	set_name("��ݺݺ", ({ "cui yingying", "cui", "ying" }));
	set("long", "�����ü������������Ƕ��۾����ĵ�ֱ���Թ��˻��ǡ�\n");
	set("title", "����Ů��");
	set("gender", "Ů��");
	set("age", 17);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}
	
