// Npc: /kungfu/class/shaolin/da-mo.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("��Ħ����", ({
		"da mo",
		"da",
		"mo",
	}));
	set("long",
		"����һλ���������������ɮ����һϮ���ݽ�˿������ġ�\n"
		"��ȴ�����⣬Ŀ�̴�Ц���������飬һ�ɵõ���ɮ���ơ�\n"
                "�����������ɿ�ɽ���桢�������ֵ�������ɮ��Ħ��ʦ��\n"
	);

	set("title", HIR"���ֿ�ɽ��ʦ"NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 80);
	set("shen_type", 1);
	set("str", 30);
        set("per",20);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 3500);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("buddhism", 180);
	set_skill("literate", 130);

	set_skill("blade", 200);
	set_skill("claw", 200);
	set_skill("club", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("finger", 200);
	set_skill("force", 200);
	set_skill("hand", 200);
	set_skill("parry", 200);
	set_skill("staff", 200);
	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("whip", 200);

	set_skill("banruo-zhang", 200);
	set_skill("cibei-dao", 200);
	set_skill("damo-jian", 200);
	set_skill("fengyun-shou", 200);
	set_skill("fumo-jian", 200);
	set_skill("hunyuan-yiqi", 200);
	set_skill("jingang-quan", 200);
	set_skill("longzhua-gong", 200);
	set_skill("luohan-quan", 200);
	set_skill("nianhua-zhi", 200);
	set_skill("pudu-zhang", 200);
	set_skill("qianye-shou", 200);
	set_skill("sanhua-zhang", 200);
	set_skill("riyue-bian", 200);
	set_skill("shaolin-shenfa", 200);
	set_skill("weituo-gun", 200);
	set_skill("wuchang-zhang", 200);
	set_skill("xiuluo-dao", 200);
	set_skill("yingzhua-gong", 200);
	set_skill("yijinjing", 250);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);

	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("������", 34, "����");
	setup();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	if ( ob_fam["generation"] != 36 )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
		return;
	}

        if ((ob->query_int() < 40) || (ob->query("PKS") > 3 )) 
        {
                command("say ���¶���һ��Ե�֡�");
                command("say " + RANK_D->query_respect(ob) + "�����Ե��������ذɡ�");
		return;
	}

	if (ob->query_skill("dodge",1)>=150 &&
		ob->query_skill("force",1)>=150 &&
		ob->query_skill("parry",1)>=150 &&
		ob->query_skill("buddhism",1)>=150)
	{
		command("say �����ֵ�һ����֮�ţ����Ǵ��ϻ� !");
		name = ob->query("name");
		new_name = "��" + name[2..3];
		ob->set("name", new_name);
	
		command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɶ��ֱ����� !");
		command("recruit " + ob->query("id"));
	}
	else
		command("say �����ھ�������Ҳ̫���˵�� !");
	return;
}

