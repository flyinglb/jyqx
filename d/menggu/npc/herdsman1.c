inherit NPC;

void create()
{
        set_name("������", ({ "muma ren", "ren", "heardsman" }));
        set("gender", "����");
        set("age", 30 + random(10));

        set("long", "һ���ɹŴ󺺣�����������ޣ�����һȺ��\n");

        set("attitude", "friendly");

        set("combat_exp", 5000);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("whip", 20);

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("inquiry", ([
                "�ɹ�" : "��������ɹŲ�ԭ��\n",
                "�ɹŲ�ԭ" : "��ԭ���ס�ųɼ�˼����������������Ľ�����\n",
                "��ԭ" : "��ԭ���ס�ųɼ�˼����������������Ľ�����\n",
                "�ɼ�˼��" : "�����ڲ�ԭ�ϲ���·�����ҵ���\n",
        ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		"����󺺿��ĵ�˵�����д��ڣ����ԭ����û��˭���۸������ɹ��ˡ�\n",
		"������˷ܵ�˦��˦��ޡ�\n",
        }) );

        carry_object(__DIR__"obj/mcloth")->wear();
        carry_object(__DIR__"obj/bian")->wield();
}


