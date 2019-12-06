// shenzhao.c
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��������", ({
		"shen zhao",
		"shen",
		"zhao",
	}));
	set("long",
		"����һλͺ����ɮ����һϮ��ɫ������ġ�������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 70);
	set_skill("hunyuan-yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin-shenfa", 70);
	set_skill("cuff", 75);
	set_skill("jingang-quan", 75);
	set_skill("staff", 76);
	set_skill("parry", 70);
	set_skill("buddhism", 70);
	set_skill("literate", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");

	setup();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}


