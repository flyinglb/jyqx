void create()
{
        set_name("�ɹ��帾Ů", ({ "woman" }) );
        set("gender", "Ů��" );
        set("age", 40);
        set("long", "һ���ܽ�׳���ɹ������긾Ů��\n");
        set("shen", 1000);
        set("combat_exp", 1500);
        set("env/wimpy", 80);
        set("chat_chance_combat", 50 );
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "�ɹ��帾Ů������Ц������\n",
                "�ɹ��帾Ů˵����������̲裬Ҫ��Ҫ��һ�룿\n",
                "�ɹ��帾Ů����Ŭ��Ŭ�죬��ָ��ָ���ߡ�\n",
		(: random_move :)
        }) );
	carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 100);
}

