// /u/beyond/mr/npc/gongsun.c ����Ǭ
// this is made by beyond
// update 1997.6.24
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("��ұǬ",({"gongye gan","gongye","gan"}));
        set("title","��ϼׯׯ��");
  	set("long", 
              "�����ǹ���Ľ�ݳ�ϼׯ��ׯ����\n");
        set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 46);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	set("combat_exp", 850000);
	set("score", 85000);
       set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.qixing" :)
           }));
  
        set_skill("dodge",100);
        set_skill("force", 100);
	set_skill("yanling-shenfa", 130);
        set_skill("parry", 100);
	set_skill("murong-jianfa", 130);
        set_skill("literate", 130);
        set_skill("sword", 130);
        set_skill("finger", 130);
        set_skill("shenyuan-gong", 130);
        set_skill("canhe-zhi", 130);
        set_skill("strike", 130);
        set_skill("xingyi-zhang", 130);

	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("strike", "xingyi-zhang");
        map_skill("finger", "canhe-zhi");
        map_skill("parry", "murong-jianfa");
        map_skill("sword", "murong-jianfa");	
        prepare_skill("finger", "canhe-zhi");
        prepare_skill("strike", "xingyi-zhang");

	setup();
        carry_object(__DIR__"obj/cloth2")->wear();
        carry_object(__DIR__"obj/changjian")->wield();        
        create_family("����Ľ��",3,"����");
        set("inquiry", ([
            "name" : "�Ҿ��ǹ���Ľ�ݳ�ϼׯׯ������Ǭ��\n",
            "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
            "rumors" : "Ľ�ݹ��ӵ��Ա�֮������ʩ��������������\n",
            "����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
            "����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
            "������" : "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�\n",
            "�˰ٴ�" : "�˰ٴ����Ҵ�磬������������ׯ��ׯ����\n",
            "����ͬ" : "����ͬ�������ܣ�����������ׯ��ׯ����������ϲ��˵����Ҳ����Ҳ����\n",
            "�粨��" : "�粨�������ĵܣ�����������˪ׯ��ׯ����������ϲ�������˴�ܡ�\n",
            "����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
            "����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
            "��٢��ɽׯ" : "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��\n",
            "��ʩˮ��" : "���������������֮���ڣ��ҿɲ������˵��\n",       
       ]));        
       }
void attempt_apprentice(object ob)
{
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
	command("recruit " + ob->query("id"));
	ob->set("title","����Ľ�ݵ��Ĵ�����");
}

