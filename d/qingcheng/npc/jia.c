// jia.c 

inherit NPC;

void create()
{
	set_name("���˴�", ({ "jia renda", "jia", "renda" }));
	set("gender", "����");
	set("age", 25);
	set("long", "�����ǡ�����ɡ�����Ϊͬ�Ų��ݡ����´�ļһ\n");

	set("combat_exp", 30000);
	set("shen_type", -1);

	set_skill("sword", 30);
	set_skill("pixie-sword", 30);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	map_skill("parry", "pixie-sword");
	map_skill("sword", "pixie-sword");
	create_family("�����", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
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
	if (ob->query("gender")=="Ů��")
		say("���˴���ƤЦ��������λ���������Ӳ��Ҫ�á�һ�������
ȴ�Ƕ�Ь̤���࣬��תʯ��Ƥ�������Ӻ�һ�Ŵ���Ƥ��\n");
	else say("���˴���˰��ۣ������ӵģ������ö�ү��˭��\n");
        return;
}
