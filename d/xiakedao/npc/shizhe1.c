// shizhe1.c

inherit NPC;

void create()
{
        set_name("����", ({ "waiter","zhe"}) );
        set("gender", "����" );
        set("age", 14);
        set("long", "һ�����Ż��µĺ��ӡ�\n");
        set("shen_type", 1);
        set("combat_exp", 3000);
        set("str", 20);
        set("dex", 25);
        set("con", 20);
        set("int", 25);
        set("attitude", "friendly");
        create_family("���͵�", 2, "����");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}


