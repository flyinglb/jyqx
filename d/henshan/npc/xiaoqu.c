// xiaoqu.c

inherit NPC;

void create()
{
	set_name("������",({ "qu feiyan", "qu" }) );
        set("gender", "Ů��" );
        set("age", 12);
        set("long", 
"���������ϵı�����Ů������ʮ���������˰ɡ�\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 70);
//        set("shen", 100);
	set("shen_type", 1);
        set("per", 26);
        set("str", 30);
        set("dex", 30);
        set("con", 30);
        set("int", 30);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

