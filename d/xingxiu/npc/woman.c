// /d/xingxiu/npc/woman.c
// Jay 3/17/96

inherit NPC;

void create()
{
        set_name("ά����帾Ů", ({ "woman" }) );
        set("gender", "Ů��" );
        set("age", 40);
        set("long", "һ�����ֵ�ά��������긾Ů��\n");
        set("shen", 1000);
        set("combat_exp", 150);
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "ά����帾Ů������Ц������\n",
                "ά����帾Ů˵����С������ѽ������\n",
                "ά����帾Ů����Ŭ��Ŭ�죬��ָ��ָ���ߡ�\n",
        }) );
   carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 100);
}

