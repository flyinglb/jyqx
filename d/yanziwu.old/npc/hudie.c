//hudie.c

inherit NPC;

void create()
{
        set_name("����", ({"hudie"}) );
        set("race", "Ұ��");
        set("age", 8);
        set("long", "����һֻ�ڻ����������ĺ������ƺ��������ء�\n");

        set("str", 20);
        set("dex", 50);

        set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
        set("verbs", ({ "bite", "poke" }) );

        set_temp("apply/attack", 33);
        set_temp("apply/armor", 20);

        set("chat_chance", 5);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
        "�����ɹ��������������������������������������ץס��ʱ�����ַ����ˡ�\n",
         }) );

        setup();
}

