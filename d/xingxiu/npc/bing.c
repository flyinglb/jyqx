// bing.c �ٱ�

inherit NPC;

void create()
{
        set_name("�ٱ�", ({ "guan bing", "bing" }));
        set("age", 32);
        set("gender", "����");
        set("long", "���Ǹ����߶�����ϱ�����Ͳ�С�ˣ�����δ�ɼҡ�\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);


        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "�ٱ��ȵ����󵨵��񣬾����췴���ɣ�\n",
                "�ٱ��ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
        }));
        setup();
        carry_object(__DIR__"obj/gangdao")->wield();
        carry_object(__DIR__"obj/junfu")->wear();
}

int accept_fight(object me)
{
        command("say ��ү���ر߹��۵�Ҫ����û�պ�" + RANK_D->query_respect(me)
		+ "�����档\n");
        return 0;
}

