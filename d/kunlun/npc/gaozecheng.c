inherit NPC;
void create()
{
        set_name("�����", ({ "gao zecheng", "gao" }));
        set("title", "������");
        set("long", 
                "����־�Ѿ�������������ﲻ����ʲô��\n");
        set("gender", "����");
        set("age", 29);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 22);
        set("dex", 28);
        set("per", random(15) + 10);
        set("no_xi", 1);
        set("max_qi", 200);
        set("max_jing", 100);
        set("neili", 50);
        set("max_neili", 50);
        set("jiali", 100);
        set("combat_exp", 5000);
        set("shen",0);
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("sword", 30);
        set_skill("parry", 30);

        create_family("������", 5, "����");

        setup();
        carry_object("/clone/cloth/male1-cloth")->wear();
        
}