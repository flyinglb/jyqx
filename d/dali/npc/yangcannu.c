// yangcannu.c

inherit NPC;

void create()
{
	set_name("����Ů",({ "yangcan nu", "girl" }) );
        set("gender", "Ů��" );
        set("age", 21);
        set("long", "һ������İ��Ĵ帾�����Ϸ�˿Ϊ����\n");
 	set_temp("apply/defense", 5);
	set("combat_exp", 5000);
//        set("shen", 100);
	set("shen_type", 1);
        set("per", 21);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/bduanqun")->wear();
}

