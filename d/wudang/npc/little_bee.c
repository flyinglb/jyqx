// little_bee.c

inherit NPC;

void create()
{
	set_name("С�۷�", ({ "little bee", "bee"}) );
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ������ȥ��С�۷䡣\n");
	
	set("str", 30);
	set("dex", 40);

	set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
	set("verbs", ({ "bite", "poke" }) );

	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	"С�۷������˷ɹ���������ͷ��ת��һȦ���з����ˡ�\n",
	 }) );

	setup();
}

