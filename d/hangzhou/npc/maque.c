// mayue.c
inherit NPC;
void create()
{
        set_name("��ȸ", ({ "maque" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�ÿɰ�����ȸŶ��\n���ڲݵ��ϱ�����ȥ�ģ���ͣ��ߴߴ������\n");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 50);
        set("chat_msg", ({"��������.......\n",
                (: this_object(), "random_move" :),
        }));
        set_temp("apply/dodge", 10);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 10);
        setup();
}
