// xier.c

inherit NPC;

void create()
{
        set_name("��ϲ��", ({ "jin xier","jin" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("str", 16);
        set("con", 24);
        set("dex", 11);
        set("per", 17);
        set("int", 14);
        set("long","��ϲ������ٹȵ�Ѿ�ߡ�\n");
        set("attitude", "friendly");

        set("max_neili", 200);
        set("neili", 200);
        set("force_factor", 10);

        set("combat_exp", 5000);

        set_skill("unarmed", 30);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("force", 50);


        setup();

        carry_object("/d/wanjiegu/npc/obj/mini-dress")->wear();
        carry_object("/d/wanjiegu/npc/obj/shoes")->wear();
}

