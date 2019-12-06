// zhang.c ������

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "zhang-sanfeng", "zhang" }));
	set("nickname", "��������");
	set("long", 
		"�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
		"��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷���\n"
		"��ĸߴ��������꣬������⣬��ü�԰ס�\n");
	set("gender", "����");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 500000);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("liangyi-jian", 200);
	set_skill("wudang-jian", 200);
	set_skill("taoism", 150);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");

	create_family("�䵱��", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
        command("say ���к���Ӧ��������ֱ��������������ֱ��");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="feng-qingyang")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

