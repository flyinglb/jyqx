// cuihua.c

inherit NPC;

void create()
{
	set_name("�仨",({ "cui hua", "hua" }) );
        set("gender", "Ů��" );
        set("age", 25);
        set("long", "���Ǹ��������޵��ٸ���ʱ��ʱ�����۽�����ɨһ�ۡ�\n");

//      set("shen", -100);
        set("shen_type", -1);
        set("str", 15);
        set("dex", 18);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 200);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 10);
        set("attitude", "peaceful");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

