// shijiang.c

inherit NPC;

void create()
{
	set_name("ʯ��",({ "shi jiang", "jiang" }) );
        set("gender", "����" );
        set("age", 52);
        set("long", "����һ����ĥ����ʯ��ʯ��������ֻ����һ�����磬ȫ�����˺�ʵ�ļ��⡣\n");
        set_temp("apply/defense", 15);
	set("combat_exp", 1700);
	set("shen_type", 1);
        set("per", 18);
        set("str", 24);
        set("dex", 25);
        set("con", 36);
        set("int", 15);
        set("attitude", "friendly");
        set("chat_chance",2);
        set("chat_msg", ({
"ʯ����һ��ûһ�µ��������е�һ�鱮�ģ���������ţ�����ɽ֮��ʢ����ʯ��
���ƴ���ʯ������Ҳ��ʯ���������¡���\n"
        }));

        setup();
        carry_object("/clone/weapon/hammer")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

