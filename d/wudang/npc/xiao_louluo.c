// xiao_louluo.c

inherit NPC;

void create()
{
        set_name("С���", ({"xiao louluo", "louluo"}) );
        set("gender", "����" );
        set("age", 18);
        set("long", "����һ����Ͳ����С��ޣ����ǵ�һ�γ��������ޱ����⡣\n");

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 500);
		set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","aggressive");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 10);
}
