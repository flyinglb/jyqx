// tongzi.c ����ͯ��

inherit NPC;

void create()
{
	set_name("����ͯ��", ({ "tong zi", "tong" }));
	set("age", 15);
	set("gender", "����");
	set("long", "һ��ü��Ŀ���ͯ�ӣ�������Ͳ���������嶾���洫��\n");
	set("attitude", "peaceful");
       set("max_qi",600);
	set("str", 25);
	set("dex", 25);
	set("combat_exp", 40000);
	set("shen_type", -1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 60);

	setup();
//	carry_object(__DIR__"obj/ganggou")->wield();
	carry_object(__DIR__"obj/jinyi")->wear();
}

