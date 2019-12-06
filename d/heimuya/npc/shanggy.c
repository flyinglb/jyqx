//tonbaiwei.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int do_join(string arg);

void greeting(object);
void init();
void create()
{
	set_name("�Ϲ���", ({ "shangguan yun","shangguan","yun"}) );
	set("gender", "����" );
	set("age", 40);
	set("title" ,HIW"�������"NOR+WHT"�׻���"NOR"����");
	set("long", "�����ֳ���, ˫Ŀ�����Ȼ, �������ơ�\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 30);

	set("max_qi", 800);
	set("max_jing",800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	set("combat_exp", 360000);
	set("score", 30000);

	set_skill("force", 80);
	set_skill("dodge", 120);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("staff",100);
	set_skill("hamagong",70);
	set_skill("chanchu-bufa", 120);
	set_skill("lingshe-zhangfa", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

	create_family(HIW"�������"NOR,2,"���� �׻��ó���");

	set("chat_chance", 3);
	
	setup();
         carry_object(__DIR__"obj/gangzhang")->wield();
         carry_object(__DIR__"obj/cloth")->wear();
         carry_object(__DIR__"obj/zhenzhu")->wear();

}



void attempt_apprentice(object ob)
{
     command("say ���ǻ���֮��, ��ô����ͽ�ء�׳ʿ������ذ�!\n");
}
void init()
{
	add_action("do_join","join");
}

#include "/d/heimuya/npc/riyueshenjiao.h"; 

