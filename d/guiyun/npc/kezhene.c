// kezhene.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({ "ke zhene", "ke" }));
	set("title", "��������");
	set("nickname", HIM"��������"NOR);
	set("long", "����һ���������ڵ�Ϲ�ӣ���������һ���ִ�����ȡ�ֻ����
������������ɫ�����˵أ������׶�̬֮��\n");
	set("gender", "����");
	set("age", 44);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 12);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 20);
	set("combat_exp", 400000);
	set("score", 6000);

	set_skill("force", 80);
	set_skill("taixuan-gong", 80);
	set_skill("dodge", 80);
	set_skill("lingxu-bu", 80);
	set_skill("unarmed", 80);
	set_skill("changquan", 80);
	set_skill("staff", 80);
	set_skill("juemen-gun", 80);
	set_skill("parry", 80);
	set_skill("throwing", 80);
	set_skill("feixing-shu", 80);

	map_skill("force", "taixuan-gong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "lingxu-bu");
	map_skill("staff", "juemen-gun");
	map_skill("parry", "juemen-gun");
	map_skill("blade", "feixing-shu");

	set("inquiry", ([
		"����" : "���������ǵĹ�ͽ����\n",
		"��������" : "�����ɲ��ҵ������������ý������и��˺Žн����߹֣�\n",
		"�����߹�" : "�߹�Ҳ����еģ���\n",
		"�𴦻�" : "������������壬�������ӣ�\n",
		"�����" : "����Ϲ���ң���Ҫ���ģ���\n",
		"���"   : "�����Ҷ��ܡ�\n",
		"������"   : "���������ܡ�\n",
		"��ϣ��"   : "�������ĵܡ�\n",
		"�Ű���"   : "��������ܡ�\n",
		"ȫ��"   : "���������ܡ�\n",
		"��СӨ"   : "���������á�\n",
		"÷����"   : "�����ʬ�����Ҵ�磬�˳�һ��Ҫ����\n",
	]));

        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );


	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
