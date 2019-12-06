// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

inherit NPC;

void create()
{
        set_name("ŷ����", ({ "ouyang ke", "ouyang", "ke" }));
        set("long", "����ҡ���ȣ��������š�\n");
        set("title", "����ɽ��ׯ��");
        set("gender", "����");
        set("age", 27);

        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("force", 50);

        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 20);
        set("combat_exp", 50000);
        set("score", 5000);

        set("attitude", "peaceful");
        set("shen_type", -1);
        setup();
}
