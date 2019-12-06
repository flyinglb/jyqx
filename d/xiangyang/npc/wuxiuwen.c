// wuxiuwen.c

#include <ansi.h>

inherit NPC;
string ask_me_1(string name);
string ask_me_2(string name);
void create()
{
	set_name("������", ({"wu xiuwen", "wu", "xiuwen"}));
	set("title", HIY"����������"NOR);
	set("gender", "����");
	set("age", 21);
	set("long", "���ǹ����Ķ����ӣ�����ǿ�ɣ�ר�Ÿ�����ڡ�\n");
 	set("attitude", "peaceful");
	
	set("per", 23);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("inquiry", ([
		"����" : "������ʦĸ��\n",
		"����" : "������ʦ����\n",
	]));

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	
	set("combat_exp", 80000);
	set("score", 20000);

	set("huju_count", 20);
	set("beixin_count", 2);
	 
	set_skill("force", 50);			// �����ڹ�
	set_skill("huntian-qigong", 50);	// ��������
	set_skill("unarmed", 50);		// ����ȭ��
	set_skill("xianglong-zhang", 50);	// ����ʮ����
	set_skill("dodge", 50);			// ��������
	set_skill("xiaoyaoyou", 50);		// ��ң��
	set_skill("parry", 50);			// �����м�
        set("inquiry", ([
		"������" : (: ask_me_1, "huwan" :),
		"������" : (: ask_me_1, "huyao" :),
		"Ƥ����" : (: ask_me_1, "shoutao" :),
		"ƤΧ��" : (: ask_me_1, "weibo" :),
		"��ָ��" : (: ask_me_1, "zhitao" :),
                "������" : (: ask_me_2, "beixin" :)
        ]));
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}
string ask_me_1(string name)
{
	object ob;
	
	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ�����������������������Ҫ�ˣ� ����̰�����У�";

	if (query("huju_count") < 1)
		return "��Ǹ�������ò���ʱ�򣬷����Ѿ������ˡ�";

	ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());

	add("huju_count", -1);

	message_vision("�����ĸ�$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�����Ҫ��ס������ֻ�ɷ������䣬����ƾ�˷������ˡ�";
}

string ask_me_2(string name)
{
	object ob;
	
	if (query("beixin_count") < 1)
		return "��Ǹ�������ò���ʱ�������Ѿ������ˡ�";

	ob = new("/d/shaolin/obj/" + name);
	ob->move(this_player());

	add("beixin_count", -1);

	message_vision("�����ĸ�$Nһ��" + ob->query("name") + "��\n", this_player());

	return "��ȥ�ɡ�����Ҫ��ס�����������Ƿ��������ƾ�˷������ˡ�";
}
