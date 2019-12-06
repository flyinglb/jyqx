// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("���ෲ", ({"island master", "long", "master"}));
	set("nickname", "��������");
	set("gender", "����");
	set("age", 80);
	set("long", 
		"���ѵ����Ǵ�˵�е����͵��������ෲ��\n������ȥ��һ������������죬���������а�����䡣\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("force", 10000);
	set("max_force", 10000);
	set("force_factor", 50);
	
	set("combat_exp", 2000000);
	set("score", 500000);
	
	set_skill("force", 200);
	//set_skill("xiake-force", 150);
	set_skill("unarmed", 150);
	//set_skill("xiake-strike", 150);
	set_skill("dodge", 150);
	//set_skill("xiake-steps", 150);
	//set_skill("move", 100);
	set_skill("literate", 100);
	
	//map_skill("force", "xiake-force");
	//map_skill("unarmed", "xiake-strike");
	//map_skill("dodge", "xiake-steps");
	//map_skill("move", "xiake-steps");
	
	setup();
	create_family("���͵�", 3, "����");
}
	

