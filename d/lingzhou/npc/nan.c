// nan.c

inherit NPC;
#include <ansi.h>;
void create()
{

	set_name("�Ϻ�����", ({ "nanhai eshen", "eshen" }));
	set("gender", "����");
	set("nickname", HIG"�����ɷ"NOR);
	set("age", 34);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "���˵�һ���Դ�������Ѱ����һ��������¶����ɭɭ�����ݣ�
һ���۾�ȴ����Բ��С��\n");
	set("combat_exp", 250000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("neili", 2000); 
	set("max_neili", 2000);
	set("jiali", 100);

	set_skill("strike", 100);
	set_skill("claw", 100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sanyin-wugongzhao", 100);
	set_skill("chousui-zhang", 100);
	set_skill("huagong-dafa", 100);
	set_skill("shaolin-shenfa", 100);
	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "huagong-dafa");
	map_skill("parry", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	prepare_skill("strike", "chousui-zhang");

	setup();
	carry_object("/kungfu/class/taohua/obj/bupao")->wear();
}

