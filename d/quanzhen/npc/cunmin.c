// cunmin.c

inherit NPC;

void create()
{
        set_name("����", ({ "cun min", "min" }) );
        set("gender", "����" );
        set("age", 30);
        set("long", "һ�������ׯ�ں��ӡ�\n");
        set("attitude", "friendly");
        set("combat_exp", 500);
        set("shen", 100);
        set("shen_type", 1);
        set("str", 22);
        set("dex", 18);
        set("con", 18);
        set("int", 13);
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
"����������ȫ��̵ĵ�ү�ǣ���ɽ��ҧׯ�ڵ����ȫ�����Ǹ������ˡ�\n",
"����ͻȻ������Ȼ����ɫ��������ճɲ����ҵø�ȫ��̵ĵ�ү���͵�
��ȥ�������ǳ����ʡ�\n",
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("coin",100);
}

