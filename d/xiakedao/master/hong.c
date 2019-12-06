// sample master.c code

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void consider();

void create()
{
	set_name("���߹�", ({"hong-qigong", "hong", "qigong"}));
	set("nickname", CYN"��ؤ"NOR);
	set("gender", "����");
	set("age", 75);
	set("long", 
		"������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_msg", ({
		"���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
		"���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
		"���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
//		(: random_move :),
	}));
//	set("inquiry", ([
//		"������" : "����������������\n",
//		"ؤ��" : "����������������\n",
//		"��ʦ" : "�����ȥ�����ŵ��Ұ��ܶ��³�нš�\n",
//	]));

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);
	
	set("combat_exp", 1000000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 150);             // �����ڹ�
	set_skill("huntian-qigong", 150);    // ��������
	set_skill("unarmed", 180);           // ����ȭ��
	set_skill("xianglong-zhang", 180);   // ����ʮ����
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 150);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("staff", 150);             // ��������
	set_skill("dagou-bang", 150);        // �򹷰���
	set_skill("begging", 100);           // �л�����
	set_skill("checking", 100);          // ����;˵
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	
	create_family("ؤ��", 17, "����");
	setup();
	
	carry_object("/kungfu/class/gaibang/obj/yuzhu_zhang");
}

