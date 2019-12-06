// xiaolu.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("½��Ӣ", ({ "lu guanying", "lu" }));
	set("title", "����ׯ��ׯ��");
	set("long", "
���ǹ���ׯ��ׯ��½��Ӣ�������������������׳����
���ж�֮�����Ķ��ţ�ǫ������һ�������ӵܷ緶��
����������̫��Ⱥ�������죬��֪�����Ǽ١�\n");
	set("gender", "����");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 26);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 600);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 150000);
	set("score", 6000);

	set_skill("force", 50);
	set_skill("hunyuan-yiqi", 50);
	set_skill("dodge", 80);
	set_skill("shaolin-shenfa", 50);
	set_skill("strike", 50);
	set_skill("banruo-zhang", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("cibei-dao", 50);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "cibei-dao");
	map_skill("blade", "cibei-dao");

	set("inquiry", ([
		"����ׯ" : (: ask_me :),
	]));

	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	add_action("do_decide", "decide");
}
string ask_me()
{
	object me = this_player();
	me->set_temp("guiyun/decide",1);
	return "����ׯ�������¾Ӵ������"+RANK_D->query_respect(me)+"����(decide)���ҿ�����һ���Ϊ������\n";
}
int do_decide()
{
	object ob, me;
	me = this_player();
	if (!me->query_temp("guiyun/decide"))
	{
		message_vision("$N��$n��ֵ�˵������Ҫ�������\n", this_object(), me);
		return 1;
	}
	me->delete_temp("guiyun/decide");
	ob = new(__DIR__"obj/xin");
	ob->move(me);
	message_vision("$N˫�ֱ�ȭ������������ׯ�������ˡ�\n", me);
	message_vision("$N˵�����ã�\n", this_object());
	message_vision("$N��$nһ�����š�\n", this_object(), me);
	message_vision("$N˵������λ"+RANK_D->query_respect(me) + "���ȵ���ׯ�̺����գ��Ժ���ͼ����\n", this_object());
	return 1;
}
