// huogong.c �𹤵���
// By Lgg,1998.10

inherit NPC;

void create()
{
        set_name("�𹤵���", ({"huogong"}));
        set("gender", "����");
        set("age", 35);
        set("class", "taoist");
        set("long",
                "����ȫ����ƹܳ����Ļ𹤵��ˡ�\n");
        set("attitude", "friendly");

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 300);
        set("max_qi", 300);
        set("jing", 200);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 0);

        set("combat_exp", 15000);

        set_skill("force", 50);
        set_skill("xiantian-qigong", 40);    //��������
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 50);   //���㹦
        set_skill("parry", 50);
        set_skill("strike",50);

        map_skill("force", "xiantian-qigong");
        map_skill("dodge", "jinyan-gong");


        setup();

        carry_object(__DIR__"obj/grayrobe")->wear();

}

