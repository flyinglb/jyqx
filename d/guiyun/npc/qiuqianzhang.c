// jiading.c �Ҷ�

inherit NPC;

void create()
{
	set_name("��ǧ��", ({ "qiu qianzhang", "qiu" }));
	set("nickname", "����ˮ����");
	set("gender", "����");
	set("age", 65);
	set("long", "���и��ܵܽ���ǧ�������и����ý���ǧ�ߡ����Լ�����Ȼ�ȵܵ�
������ǧ�ߣ������ø��Ƕ��˾�ǧ�ߣ����ϵĹ�����ȴ������ϡ����
�پ���ߡ�\n"); 
	set("per",14);
	set("combat_exp", 50000);
	set_skill("dodge", 50);
	set_skill("lingxu-bu", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("changquan", 50);
	map_skill("dodge", "lingxu-bu");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");
	set("shen_type", -1);
	setup();

	add_money("silver",3);
	carry_object("/clone/misc/cloth")->wear();
}

