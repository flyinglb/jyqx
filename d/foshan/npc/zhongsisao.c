// zhongsisao.c

inherit NPC;

void create()
{
	set_name("����ɩ", ({ "zhong sisao","zhong","sisao" }) );
	set("gender", "Ů��");
	set("age", 35);
	set("long",
"�������Ӱ��ĵ����š�����ү��Ժ������ʮֻ�ʶ죬��Ȼ������һֻ���Ҷ�\n"
"˵����ҵ�С���ӡ�С�����ֵ���͵�ˣ���Ѳ������ȥ����һ״�����۱���\n"
"����������ȥ���ε�����һϢ������ɩ����һ����������ġ����ϻؼ��\n"
"һ������С���ӣ�һ�����˱��˵��������������ڣ�һ��������ȥ��\n"
"����ɩ�ڱ���үү��ǰ���˼�����ͷ��˵����������үү���Һ��Ӿ�����͵\n"
"�˼ҵĶ졣�����껹ֻ���꣬�������࣬˵��������ڲ���ү��ǰ˵ʲô��\n"
"�ң����ң�С����һ�Һ��ⲻ�ף��߹����˻ߣ����²�����ֻ���뱱��үү\n"
"��ԩ����˵����������һ���㽫С���ӵĶ������ˡ��Լ�Ҳ�����ˡ�\n");
	set("combat_exp", 20000);
        set("shen_type", 1);
	set("attitude", "aggressive");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("chat_chance", 5);
	set("chat_msg", ({
		"����ɩ˻����ɤ�Ӻ����������أ������أ�û��͵��û��͵����\n",
		(: random_move :)
	}) );

	set_skill("blade", 30);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();
        carry_object(__DIR__"obj/caidao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
