// /u/beyond/mr/npc/deng.c �˰ٴ�
// this is made by beyond
// update 1997.6.24
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("�˰ٴ�",({"deng baichuan","deng","baichuan"}));
        set("title","����ׯׯ��");
  	set("long", 
              "�����ǹ���Ľ������ׯ��ׯ����\n");
        set("age", 25);
	set("attitude", "friendly");
	set("shen_type", 1);
set("str", 36);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	
set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
set("combat_exp", 750000);
	set("score", 85000);

        set_skill("finger",130);
        set_skill("dodge",130);
        set_skill("force", 130);
	set_skill("shenyuan-gong", 130);
	set_skill("yanling-shenfa", 130);
        set_skill("parry", 130);
	set_skill("canhe-zhi", 150);
        set_skill("literate", 130);

	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "xingyi-zhang");
        map_skill("finger", "canhe-zhi");	

	prepare_skill("finger","canhe-zhi");
	setup();
        carry_object(__DIR__"obj/cloth2")->wear();        
        create_family("����Ľ��",3,"����");
        set("inquiry", ([
            "name" : "�Ҿ��ǹ���Ľ������ׯׯ���˰ٴ���\n",
            "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
            "rumors" : "Ľ�ݹ��ӵ��Ա�֮������ʩ��������������\n",
            "����" : "����ס������ˮ鿣���Ľ�ݹ��ӵ�����Ѿ�ߣ�������������һͬ�̷�ӡ�\n",
            "����" : "���̹���ס������С��������Ҫ�ݼ�Ľ�ݹ��ӵ��˶�Ҫ�������ﾭ����\n",
            "������" : "��������Ľ�ݹ��ӵı��ã���֪��ʲôʱ�����ǳ��ס�\n",
            "����Ǭ" : "����Ǭ���Ҷ��ܣ����������ϼׯ��ׯ����\n",
            "����ͬ" : "����ͬ�������ܣ�����������ׯ��ׯ����������ϲ��˵����Ҳ����Ҳ����\n",
            "�粨��" : "�粨�������ĵܣ�����������˪ׯ��ׯ����������ϲ�������˴�ܡ�\n",
            "����ˮ�" : "����ˮ��ǰ������ס�ĵط��������ﲻԶ��\n",
            "����С��" : "����С���ǰ��̹���ס�ĵط�����С��������ˮ·�͵��ˡ�\n",
            "��٢��ɽׯ" : "��٢��ɽׯ�ǹ��ӵĹ���ס�ĵط���ƽʱ���Ҷ�����ȥ��\n",
            "��ʩˮ��" : "���������������֮���ڣ��ҿɲ������˵��\n",       
       ]));                 
        set("chat_chance",20);
       set("chat_msg",({
                "�˰ٴ��������ﵽ�����ϻض���˹��ӵĹ�Ԫ����Ҫô�ĵܵ������Ͷ��ˡ���\n",
                "�˰ٴ���������ү��ǰ���Ӱ����Ǳ���Ҳһͬ�����ˡ�\n", 
                "�˰ٴ���������үȥ�������ҵ�ͷ��������ˡ�\n",
              
        }) );
}
void attempt_apprentice(object ob)
{
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
	command("recruit " + ob->query("id"));
	ob->set("title","����Ľ�ݵ��Ĵ�����");
}

