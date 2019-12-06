// ai-laozhe.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("������", ({ "ai-laozhe", "ai" }));
	set("title", HIG"��ɽ��ʮ��������"NOR);
	set("long", 
"�����ǻ�ɽ�ĳ��ϰ����ߡ�һ���������ϵ�����������η��\n");
	set("gender", "����");
	set("age", 66);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 3800);
	set("max_qi", 3800);
	set("jing", 3600);
	set("max_jing", 2000);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 100);

	set("combat_exp", 1250000);
	set("score", 200000);

	set_skill("cuff", 180);
	set_skill("force", 170);
	set_skill("blade", 180);
	set_skill("sword", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("strike", 180);
	set_skill("zixia-shengong", 150);
	set_skill("poyu-quan", 160);
	set_skill("fanliangyi-dao", 180);
	set_skill("huashan-sword", 180);
	set_skill("hunyuan-zhang", 160);
        set_skill("feiyan-huixiang",160);
	set_skill("literate", 100);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "fanliangyi-dao");
	map_skill("blade", "fanliangyi-dao");
	map_skill("sword", "huashan-sword");
	map_skill("strike", "hunyuan-zhang");

	create_family("��ɽ��", 12, "����");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "blade.sanshen" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}
