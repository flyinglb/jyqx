// ye.c

inherit NPC;
#include <ansi.h>;
void create()
{
	set_name("Ҷ����", ({ "ye erniang", "ye" }));
	set("gender", "Ů��");
	set("nickname", HIR"�޶���"NOR);
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "һ������Ů�ӣ�������ɫ���ۣ����������ϸ�������Ѫ�ۡ�\n");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("neili", 2000); 
	set("max_neili", 2000);
	set("jiali", 100);

	set_skill("strike", 100);
	set_skill("claw", 100);
	set_skill("force", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sanyin-wugongzhao", 100);
	set_skill("chousui-zhang", 100);
	set_skill("huagong-dafa", 100);
	set_skill("kuangfeng-blade", 100);
	set_skill("shaolin-shenfa", 100);
	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "huagong-dafa");
	map_skill("blade", "kuangfeng-blade");
	map_skill("parry", "kuangfeng-blade");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	setup();
	carry_object("/kungfu/class/taohua/obj/bupao")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

