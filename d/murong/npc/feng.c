// /u/beyond/mr/npc/feng.c �粨��
// this is made by beyond
// update 1997.6.24
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("�粨��",({"feng boe","feng","boe"}));
        set("title","��˪ׯׯ��");
        set("nickname","һ���");
  	set("long", 
              "�����ǹ���Ľ����˪ׯ��ׯ����\n");
        set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 26);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	set("combat_exp", 850000);
	set("score", 85000);

        set_skill("strike",80);
        set_skill("dodge",80);
        set_skill("force", 100);
        set_skill("shenyuan-gong", 80);
        set_skill("yanling-shenfa", 80);
        set_skill("parry", 90);
        set_skill("xingyi-zhang", 80);

	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "xingyi-zhang");
        map_skill("strike", "xingyi-zhang");	
        prepare_skill("strike", "xingyi-zhang");
        setup(); 
       carry_object(__DIR__"obj/cloth2")->wear();
       
        create_family("����Ľ��",3,"����");
        set("inquiry", ([
            "name" : "�Ҿ��ǹ���Ľ����˪ׯׯׯ���粨��\n",
            "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
            "rumors" : "Ľ�ݹ��ӵ��Ա�֮������ʩ��������������\n",
            "����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
            "����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
            "������" : "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�\n",
            "�˰ٴ�" : "�˰ٴ����Ҵ�磬������������ׯ��ׯ����\n",
            "����Ǭ" : "����Ǭ���Ҷ��磬���������ϼׯ��ׯ����\n",
            "����ͬ" : "����ͬ�������磬����������ׯ��ׯ����������ϲ��˵����Ҳ����Ҳ����\n",
            "����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
            "����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
            "��٢��ɽׯ" : "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��\n",
            "��ʩˮ��" : "���������������֮���ڣ��ҿɲ������˵��\n",       
       ]));
         set("chat_chance",15);
         set("chat_msg",({
"�粨����������̹������������޲�֪�������������ҿ����۽硣��\n",
 "�粨�������Ҫ���ǹ��ӵ���¶����ɢ�����Ů��������������û�ˡ���\n",
                              
        }) );
         
}
void attempt_apprentice(object ob)
{
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
	command("recruit " + ob->query("id"));
	ob->set("title","����Ľ�ݵ��Ĵ�����");
}

