// tongzi.c ͯ��

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ͯ��", ({ "tong zi",  }));
        set("long", "����һ��ʮ����������꣬ü��Ŀ�㣬������������õ���ϲ����\n");
        set("gender", "����");
        set("age", 15);
        set("shen_type",100);
        set("attitude", "peaceful");

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 200);
        set("max_qi", 200);
        set("jing", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 10);

        set("combat_exp", 3000);
        set("score", 10);
        set_skill("force", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("hand", 40);
        set_skill("staff", 40);

        create_family("���͵�", 3, "����");
        setup();
}
