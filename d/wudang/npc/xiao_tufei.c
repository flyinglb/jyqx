// xiao_tufei.c

inherit NPC;

void create()
{
        set_name("С����", ({"xiao tufei", "tufei"}));
        set("gender", "����" );
        set("age", 22);
        set("long", "���Ǹ���������С���ˣ�ɱ��Խ������޶�����\n");

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set("combat_exp", 750);
//		set("shen", -150);
		set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","aggressive");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 30);
}

