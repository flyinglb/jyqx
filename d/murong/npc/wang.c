// /u/beyond/mr/npc/wang.c ������
// this is made by beyond
// update 1997.6.29
inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("������",({"wang furen","wang","furen"}));
	set("gender", "Ů��");
	set("rank_info/respect", "����");
        set("title","��٢��ɽׯ��");
  	set("long", 
              "��������٢��ɽׯ�����ˣ�������ȥ������ʮ�мӣ��������ȴ档\n");
        set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 20);
	set("int", 22);
	set("con", 28);
        set("per", 30);
	set("dex", 23);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1000);
	set("max_neili", 1500);
	set("jiali", 0);
	set("combat_exp", 80000);
	set("score", 15000);

        set_skill("murong-xinfa", 70);
        set_skill("dodge",70);
        set_skill("force", 70);
	set_skill("shenyuan-gong", 70);
	set_skill("yanling-shenfa", 70);
        set_skill("parry", 70);
	set_skill("literate", 70);
        set_skill("strike", 65);
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        
	setup();
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt")->wear();
        
        set("inquiry", ([
            "name" : "�Ҿ�����٢��ɽׯ�����ˣ��������ѵ�û��ʲô��ʾ��\n",
            "here" : "��������٢��ɽׯ��ׯԺ֮���ڣ��˴���Ϊ�ƽ�¥��\n",
            "rumors" : "������Ǳ���Ľ�ݲ����������ˡ�\n",
            "������" : "�������ҵı���Ů������ɱ�����������⡣\n",
            "Ľ�ݸ�" : "Ľ�ݸ������ǲ�������ֶ�����������Ա�֮����ʩ����ľ��������𽭺���\n",
            "������" : "������������٢��ɽׯ�Ĳ���֮����һ�����Ǳ����ȥ�ˡ�\n",
            "��٢��ɽׯ" : "���������٢��ɽׯ���Ҿ�����������ˡ�\n",
            "��ʩˮ��" : "���������������֮���ڣ�������ʩˮ��Ĳ����������Ƕ�Ķ�ѽ��\n",       
       ]));
}


