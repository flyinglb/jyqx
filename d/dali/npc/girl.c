// girl.c

inherit NPC;

void create()
{
	set_name("����Ů��",({ "girl" }) );
        set("gender", "Ů��" );
        set("age", 22);
        set("long", "����һ�����Ű��µİ���Ů�ӣ�����ƮƮ����̬���ȡ�\n");
 	set_temp("apply/defense", 5);
	set("combat_exp", 7000);
//        set("shen", 100);
	set("shen_type", 1);
        set("per", 24);
        set("str", 24);
        set("dex", 25);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
}

