// huoji.c
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�͵���", ({ "kedian huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18+random(20));
	set("long", "����С�͵�Ļ�ơ�\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("chat_chance", 3);
	set("chat_msg", ({
	"���˵������...��...��ɱ�ɱ�Ұ���������...����\n",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

