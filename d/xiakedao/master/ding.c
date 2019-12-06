// ding.c ������

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "ding-chunqiu", "ding" }));
	set("nickname", "�����Ϲ�");
	set("long", 
		"�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
		"��������������ò���棬�ɷ���ǡ�\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

	set_skill("force", 100);
	set_skill("huagong-dafa", 150);
	set_skill("throwing", 150);
	set_skill("feixing-shu", 150);
	set_skill("dodge", 150);
	set_skill("zhaixinggong", 150);
	set_skill("unarmed", 100);
	set_skill("chousui-zhang", 150);
	set_skill("claw", 100);
	set_skill("sanyin-wugongzhao", 150);
	set_skill("parry", 100);
	set_skill("staff", 100);
	set_skill("poison", 100);
	set_skill("tianshan-zhang", 150);
//	set_skill("literate", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");

	create_family("������", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
//      carry_object("/clone/weapon/changjian")->wield();
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
        command("say ʮ��ɱһ�ˣ������ɾ����񹦾�Ҫ���̡�");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="ouyang-feng")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

