// Npc: /kungfu/class/shaolin/qing-yuan.c
// Date: YZC 96/01/19

inherit NPC;


void create()
{
	set_name("��Ե����", ({
		"qingyuan biqiu",
		"qingyuan",
		"biqiu",
	}));
	set("long",
		"����һλ���ǿ����׳��ɮ�ˣ�����û���������ȫ���ƺ��̺�\n"
		"�������������һϮ�ײ��ڱ����ģ��ƺ������ա�\n"
	);


	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 21);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan-yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 30);
	set_skill("strike", 30);
	set_skill("qianye-shou", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "qianye-shou");
	map_skill("parry", "qianye-shou");

	prepare_skill("strike", "qianye-shou");

	create_family("������", 40, "����");

	setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("speaking");
		call_out("speaking", 1, ob);
	}
}

void speaking(object ob)
{
	if ( random(5) < 1 ) 
	{	
		switch( random(4) ) {
		case 0:
                       command("say ����ǰ��һ��������������¾ͳ�����κͱ��ߵ���¥û���֡���������\n");
		       break;
		case 1:
                       command("say ��������ȫ�ø�֭����Ļ����Ҹ��������������Ǿ��Ǳ�ɲ�ӬҲ�ɲ���ȥ��\n");
		       break;
		case 2:
                       command("say �úô��ű𶯣��Ȼ����Ȼ������ǳ�ȥ�����������Լ�Ҫ����ҿɲ��ܣ�\n");
		       break;
		case 3:
                       command("say �٣����������پ޼����������ﱻ�ع�����������������������һ����\n");
		       break;
		}
	}
}


