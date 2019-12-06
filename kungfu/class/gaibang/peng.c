// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("���о�", ({"peng youjing", "peng", "youjing"}));
	set("title", "ؤ��Ŵ�����");
	set("nickname", "�Ʋ���ͷ");
	set("gender", "����");
	set("age", 50);
	set("long", 
		"���о���ؤ���о����ɵ����죬���Ÿɾ�����������л��ӡ�\n"
		"�����Ϲ��Ŵ����Ц�ݣ�һ˫�۾����������ǵ�������\n");

	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1300);
	set("max_neili", 1200);
	set("jiali", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 90); // �����ڹ�
	set_skill("huntian-qigong", 90); // ��������
	set_skill("unarmed", 85); // ����ȭ��
	set_skill("xianglong-zhang", 80); // ����ʮ����
	set_skill("dodge", 95); // ��������
	set_skill("xiaoyaoyou", 85); // ��ң��
	set_skill("parry", 90); // �����м�
	set_skill("staff", 90); // ��������
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 18, "�Ŵ�����");
	setup();
       carry_object(__DIR__"obj/beggar-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�");
}
#include "/kungfu/class/gaibang/gaibang.h"
