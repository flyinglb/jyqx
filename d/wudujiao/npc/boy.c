// boy.c

inherit NPC;

void create()
{
	set_name("�к�",({ "boy" }) );
        set("gender", "����" );
        set("age", 12);
        set("long", 
"���Ǹ�ũ�����꣬������С��ũ����Ȼ��Ͳ��󣬿��ѳ��ĺܴ�׳�ˡ�\n");

        set("str", 16);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
	set("shen_type", 1);
//	set("shen", 100);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");

        setup();

        carry_object("/d/city/obj/cloth")->wear();
	add_money("coin",100);
}

