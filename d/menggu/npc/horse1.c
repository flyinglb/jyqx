inherit NPC;

void create()
{
        set_name("Ұ��", ({ "horse", "ye ma" }));
        set("long","һֻδ��ѱ���ĳ���Ұ��\n");
        set("race", "Ұ��");
        set("age", 1);
        set("int", 30);
        set("qi", 500);
        set("max_qi", 500);
        set("jing", 500);
        set("max_jing", 500);
        set("shen_type", 0);
        set("combat_exp",50000);
        set("chat_chance",50);
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
        set("verbs", ({ "bite","hoof" }) );
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

	set("chat_msg", ({
		"\nҰ��ϡ����˻����һ����\n"
		"\nҰ��ͻȻ��ǰ��ȥ��ֻ����һ��������\n"
		(: random_move :)
	}) );
        setup();
}

