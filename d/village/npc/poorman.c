// poorman.c

inherit NPC;

void create()
{
        set_name("�", ({ "poor man", "man" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "һ���������������ɫ�����\n");
        set("attitude", "friendly");
        set("combat_exp", 250);
//	set("shen", 50);
	set("shen_type", 1);
        set("str", 20);
        set("dex", 18);
        set("con", 17);
        set("int", 13);
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
"�������ش��˸���Ƿ��\n",
"�����׽ס�����ϵ�ʭ�ӣ��������������û�����⣬ȫ�����Ǹ�ҧ�ˡ� \n",
                (: random_move :)
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
}

