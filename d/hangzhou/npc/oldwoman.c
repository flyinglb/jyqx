// oldwoman.c

inherit NPC;

void create()
{
        set_name("�ϴ���", ({ "old woman", "woman" }) );
        set("gender", "Ů��" );
        set("age", 63);
        set("long", "һ��������˪֮ɫ�������š�\n");
//	set("shen", 1000);
	set("shen_type", 1);
	set("combat_exp", 150);
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
//        set("chat_msg_combat", ({
//               "E)7r=P5@#:I1HKDD#!I1HKDD#!\n",
//              "E)7r=P5@#:SPMA7KDD#!9bLl;/HUOB4r=YDD#!\n",
//                (: command, "surrender" :),
//        }) );
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 13);
        set("attitude", "friendly");
        set("inquiry", ([
                "��" : "������ĸ����...һ�����Ǽ���������ҵ��С��å�ɵġ�",
		"��å" : "�Ǽ���С��å���첻����ҵ������С��ͬ��Ⱦƶ�Ǯ��"
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
		"�ϴ������ĵ�˵�����Ǹ���ɱ�ģ�͵���ҵ���ĸ����\n",
		"�ϴ���̾�˿�����˵�������Ǹ�ʲ����������\n",
		"�ϴ�����������ż�������������ˡ�\n",
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", 100);
}

