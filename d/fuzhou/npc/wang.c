// wang.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "wang furen", "wang" }));
	set("gender", "Ů��");
	set("title", HIY"��"NOR);
	set("long", "��������������ү�ӵĶ�����Ů�������ھ�����ͷ���ˡ�");
	set("age", 39);

	set("combat_exp", 25000);
	set("shen_type", 1);

	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("yanxing-dao", 50);
	map_skill("parry", "yanxing-dao");
	map_skill("blade", "yanxing-dao");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
