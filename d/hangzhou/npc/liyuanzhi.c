// liyuanzhi.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������", ({ "li yuanzhi", "li", "yuanzhi"}) );
	set("gender", "Ů��");
	set("age", 16);
	set("long",
		"���Ǻ����ᶽ������ǧ���䵱����½��������ҵ��ӡ�\n");
	set("combat_exp", 200000);
        set("shen_type", 1);
        set("max_neili", 1000);
        set("neili", 1000);
        set("max_jing", 500);
        set("jing", 500);
        set("max_qi", 1000);
        set("qi", 1000);
	set("attitude", "peace");
        set("per", 26);
        set("int", 26);
        set("con", 26);
        set("str", 26);
        set("dex", 26);

	set_skill("unarmed", 75);
	set_skill("sword", 75);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("force", 70);
	set_skill("taiji-shengong", 70);
	set_skill("taiji-jian", 70);
	set_skill("taiji-quan", 70);
	set_skill("tiyunzong", 70);
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji-shengong");
	map_skill("sword", "taiji-jian");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
        create_family("�䵱��", 14, "����");

	setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/fuzhou/obj/pink_cloth")->wear();

	add_money("silver", 30);
}
