// guigongzi.c
inherit NPC;

void create()
{
	set_name("����", ({ "gongzi" }) );
	set("gender", "����" );
	set("age", 29);
	set("long", "����һ��������ӣ����õ�Ҳ�������ٷ硢һ���˲ţ���ƫƫһ˫�۾�ȴ��б����ˡ�\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 26);
	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 400);
	set("max_jing", 200);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);
	setup();
	add_money("silver", 10);
}
