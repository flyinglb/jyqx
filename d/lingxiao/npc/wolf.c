//LUCAS 2000-6-18
inherit NPC;

void create()
{
        set_name("ѩ��", ({ "xue lang","wolf", "lang" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һͷѩ�׵�ѩ�ǣ�����ֱ�������۷����̹⣬�Ǵ�ѩɽ�����͵�Ұ�ޡ�\n");
        set("attitude", "aggressive");

        set("str", 26);
        set("cor", 30);
        set("limbs", ({ "ͷ��", "����", "�Ȳ�", "β��",}) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 5000);

        set("chat_chance",50);
        set_temp("apply/attack", 25);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 18);
        set_temp("apply/defence",20);

        setup();
}

