/*  <SecCrypt CPL V3R05>  */
 
inherit  NPC;

void  create()
{
	set_name("�����",  ({"suan  xiucai","xiucai"}));
	set("age",  22);
	set("gender",  "����");
	set("long", "�����ţ��ľ�����Щ���Ų�����\n");
	set("attitude",  "peaceful");
	set("per",  22);
	set("combat_exp",  8000);
	set("shen_type",  1);
	set("class",  "scholar");
	set("force",  200);
	set("max_force",  200);
	set("force_factor",  3);
	set_skill("unarmed",  40);
	set_skill("dodge",  40);
	set_skill("parry",  40);
	setup();

	carry_object("/clone/misc/cloth")->wear();
}

