// boy.c

inherit NPC;

void create()
{
	set_name("�к�",({ "boy" }) );
        set("gender", "����" );
        set("age", 13);
        set("long", 
"���Ǹ�ƽ�����꣬��С�ڳ��л�죬�����ú��ˡ�\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
	set("shen_type", 1);
//	set("shen", 100);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

