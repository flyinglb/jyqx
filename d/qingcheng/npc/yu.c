// yu.c 

inherit NPC;

void create()
{
	set_name("���˺�", ({ "yu renhao", "yu", "renhao" }));
	set("gender", "����");
	set("age", 25);
	set("long", "�����ǡ�Ӣ�ۺ��ܣ�������㡹֮һ���书ҲԶ��ͬ�š�\n");

	set("combat_exp", 80000);
	set("shen_type", -1);

	set_skill("sword", 80);
	set_skill("pixie-sword", 80);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
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
        say ("���˺���һ�������Ӿ������˺���\n");
        return;
}
