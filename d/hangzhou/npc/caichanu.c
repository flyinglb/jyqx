// caichanu.c

inherit NPC;

void create()
{
        set_name("�ɲ�Ů", ({ "girl" }) );
        set("gender", "Ů��" );
        set("age", 19);
        set("per", 40);
        set("long", "��������Ĳɲ����һ���������ˡ�\n");
        set("combat_exp", 700);
        set("attitude", "friendly");
        set_skill("unarmed", 40);
        set_skill("parry", 25);
        set_skill("dodge", 30);

        set("chat_chance", 5);
        set("chat_msg", ({
            "�ɲ�Ů˵����ٯ����ȥ�������㷥������һ��ȥ����ã�\n",
        }) );

        setup();
        add_money("silver", 15);
        carry_object("/clone/cloth/cloth")->wear();
}

