// shipopo.c ʷ����

inherit NPC;
inherit F_UNIQUE;

void create()
{
        set_name("ʷ����", ({ "shi", "popo" }));
        set("title", "������������");
        set("gender", "Ů��");
        set("long", "����ѩɽ�������˰����ڵ����ӣ���˵���������Եò��ϣ�\n"
        "����ʮ��ǰ���𡰽���һ֦����ʷС������������ȴ�����˲�֪��\n");
        set("age", 68);

        set("int", 30);

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 500);
        set("max_jing", 500);
        set("shen_type", 1);

        set("combat_exp", 75000);
        set("attitude", "friendly");

        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("blade", 40);
        set_skill("parry", 90);
        set_skill("unarmed", 90);
        set_skill("jinwu-daofa", 70);
        set_skill("yanfly", 70);
        set_skill("houquan", 100);

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 35);


        map_skill("blade", "jinwu-daofa");
        map_skill("parry", "jinwu-daofa");
        map_skill("dodge", "yan-fly");
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
}

