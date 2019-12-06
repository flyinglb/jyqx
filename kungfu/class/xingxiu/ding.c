// ding.c ������

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_du1();
string ask_du2();

void create()
{
	set_name("������", ({ "ding chunqiu", "ding" }));
	set("nickname", "�����Ϲ�");
	set("long", 
		"�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
		"��������������ò���棬�ɷ���ǡ�\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

	set_skill("force", 150);
	set_skill("huagong-dafa", 180);
	set_skill("throwing", 150);
	set_skill("feixing-shu", 150);
	set_skill("dodge", 150);
	set_skill("zhaixinggong", 180);
	set_skill("strike", 150);
	set_skill("chousui-zhang", 180);
	set_skill("claw", 150);
	set_skill("sanyin-wugongzhao", 180);
	set_skill("parry", 150);
	set_skill("staff", 150);
	set_skill("poison", 150);
	set_skill("tianshan-zhang", 180);
	set_skill("literate", 100);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("book_count", 1);
	set("zhen_count", 1);
	set("san_count", 1);

	set("inquiry", ([
		"����" : (: ask_me :),
		"���޶���" : (: ask_me :),
		"������" : (: ask_du1 :),
		"��Ц��ңɢ" : (: ask_du2 :),
		"��ң��Цɢ" : (: ask_du2 :),
	]));

	create_family("������", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_flatter", "flatter");
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -100) {
                command("say ����Խ����Խ��׵������Ե׵ġ�");
                return;
        }
        if ((int)me->query("combat_exp") < 10000) {
                command("say �����΢ĩ���������ѧ�����ɵ������");
                return;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say ����˲������ɷ�����������������㣿");
                return;
        } else {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("��˵����ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
         || strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
                command("recruit " + this_player()->query("id"));
        } else {
                command("say ����˲������ɷ�����������������㣿");
        }
        return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

// �������ɣ�������أ��������Ž��ޱ�

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/dujing_2");
	ob->move(this_player());
	return "�ðɣ��Ȿ�����޶��������û�ȥ�ú����С�";
}
string ask_du1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_skill("poison",1)<50)
		return "��Ķ������δ�����ò������ֶ�����";
	if (query("zhen_count") < 1)
		return "�������ˣ������붼�����ˡ�";
	add("zhen_count", -1);
	ob = new("/d/xingxiu/obj/bilinzhen");
	ob->move(this_player());
	return "�ðɣ������������Щ��ɡ�";
}
string ask_du2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_skill("poison",1)<100)
		return "��Ķ������δ�����ò������ֶ�����";
	if (query("san_count") < 1)
		return "�������ˣ�����ûʲôʣ���ˡ�";
	add("san_count", -1);
	ob = new("/d/xingxiu/obj/sanxiaosan");
	ob->move(this_player());
	return "�ðɣ������ҩ���û�ȥ�Ƽ����ðɡ�";
}
