#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����", ({ "zhu jiuzhen", "zhu" }));
	set("title", HIW "ѩ��˫��" NOR);
	set("long", "�����쳤��Ķ�����Ů��\n");
	set("gender", "Ů��");
	set("age", 17);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("per", 28);
	set("str", 18);
	set("int", 20);
	set("con", 15);
	set("dex", 25);
	
	set("max_qi", 500);
	set("max_jing", 400);
	set("neili", 500);
	set("max_neili", 500);
	set("combat_exp", 80000);

        set_skill("force", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("cuff", 50);
        set_skill("whip", 50);
	set_skill("kurong-changong", 50);
        set_skill("tiannan-step", 50);
        set_skill("jinyu-quan", 50);
        set_skill("feifeng-whip", 50);
	set_skill("literate", 50);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("whip", "feifeng-whip");
	map_skill("parry", "feifeng-whip");
	prepare_skill("cuff", "jinyu-quan");

	setup();
	carry_object("/clone/cloth/female4-cloth")->wear();
	carry_object(__DIR__"obj/whip")->wield();
	add_money("silver", 10);

}
