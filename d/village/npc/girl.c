// kid.c

inherit NPC;

void create()
{
	set_name("Ů��",({ "girl" }) );
        set("gender", "Ů��" );
        set("age", 12);
        set("long", 
"���Ǹ�ũ����Ů����Ȼֻ��ʮ�������꣬����Ѿ���ʼ������\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 70);
//        set("shen", 100);
	set("shen_type", 1);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

