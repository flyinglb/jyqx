// likexiu.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�����", ({ "li kexiu", "li", "kexiu"}) );
	set("title", "�����ᶽ");
	set("gender", "����");
	set("age", 54);
	set("long",
		"�����һ��������ɷ⽮������һ���书��Ȼ�������ӡ�\n");
	set("combat_exp", 150000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set_skill("unarmed", 75);
	set_skill("blade", 75);
	set_skill("parry", 70);
	set_skill("dodge", 70);

	setup();

        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/d/city/obj/tiejia")->wear();

	add_money("silver", 30);
}
