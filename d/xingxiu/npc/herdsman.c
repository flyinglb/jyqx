// npc: /d/xingxiu/herdsman.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("������", ({ "muyang ren", "ren", "heardsman" }));
        set("gender", "����");
        set("age", 60 + random(10));

        set("long", "һ��ά������Ϻ������ż�ʮֻ��\n");

        set("attitude", "friendly");

        set("combat_exp", 1000);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("whip", 20);

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("inquiry", ([
                "������" : "���Ƕ������޺���",
                "���޺�" : "���޺�������ߡ�\n",
                "�" : "��û��ȥ������˵ֻ�в�ҩ�ĺ������ɵ�����ͽ�ֹ�ȥ��\n",
        ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
              "�����Ϻ����ĵ�˵�����ǰ������ɵ���������������һֻ��\n",
              "�����Ϻ�������������Ⱥ��������ˡ�\n",
        }) );

        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/bian")->wield();
}


