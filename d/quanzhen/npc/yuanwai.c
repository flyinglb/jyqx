// yuanwai.c
inherit NPC;

void create()
{
        set_name("��Ա��", ({ "hou yuanwai", "hou" }));
        set("long",
                "��Ա���˵���ⳤ�����ϵ��׸���˭Ҳ��֪���������ж���\n"
                "�Ҳơ�����Լ��ʮ��ͷ�����ĸ���̬̬��\n");
        set("gender", "����");
        set("age", 52);

        set("combat_exp", 12000);
        set_skill("unarmed", 45);
        set_skill("force", 42);
        set_skill("dodge", 35);
        set_temp("apply/attack", 35);
        set_temp("apply/defense", 42);

        setup();
        carry_object(__DIR__"obj/jinduan")->wear();
        add_money("silver",120);
}

