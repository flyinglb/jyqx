// huangboliu.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
int do_join(string arg);
#include <ansi.h>;
void create()
{
	set_name("�Ʋ���", ({ "huang boliu","huang","boliu"}) );
	set("gender", "����" );
	set("title",HIW"�������"HIY"������"NOR"����");
	set("nickname", HIW"������"NOR);
	set("age", 85);
	set("long", "һ�����룬ֱ�����أ���Ŀ���֮����\n");
	set("attitude", "friendly");
	set("shen_type", 1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 350000);
	set("jiali", 100);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("changquan",70);
	set_skill("tiyunzong", 80);

	map_skill("dodge", "tiyunzong");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	create_family(HIW"�������"NOR,2,"���� ����������");

	setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	add_action("do_join","join");
}

#include "/d/heimuya/npc/riyueshenjiao.h"; 


