// yun.c

inherit NPC;
#include <ansi.h>;
void create()
{

	set_name("���к�", ({ "yun zhonghe", "yun" }));
	set("gender", "����");
	set("nickname", HIY"���׼���"NOR);
	set("age", 34);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("long", "���˳����ָ�������һ�˴���ͣ�˵������������֣�ʮ����
��������һ��������һ��ɫ����ģ����\n");
	set("combat_exp", 150000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 50);

	set_skill("strike", 80);
	set_skill("claw", 80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sanyin-wugongzhao", 80);
	set_skill("chousui-zhang", 80);
	set_skill("huagong-dafa", 80);
	set_skill("shaolin-shenfa", 80);
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

