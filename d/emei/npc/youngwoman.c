// youngwoman.c

inherit NPC;

void create()
{
        set_name("�����ٸ�",({ "nianqing shaofu","shaofu" }) );
        set("gender", "Ů��" );
        set("age", 16);
        set("long",
"����һ����;ƣ���������ٸ���\n");
        set_temp("apply/defense", 5);
        set("combat_exp", 1000);
        set("shen", 500);
        set("shen_type", 1);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_skill("sword", 10);
        set_skill("force", 10);
        set_temp("apply/attack", 10000);
        set_temp("apply/defense", 10000);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        set("attitude", "friendly");
        setup();
        carry_object("/d/city/obj/cloth")->wear();
}
