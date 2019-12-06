// qqren.c �Ϲٽ���

inherit NPC;
int ask_qiubai();
inherit F_MASTER;

void create()
{
    set_name("�Ϲٽ���", ({ "shangguan jiannan", "shang", "shangguan", "jiannan"}));
    set("nickname", "����ˮ��Ư");
	set("long", 
        "��λ�Ϲٰ�������һλ����֮ʿ�����ư��������κ��������٣�������\n"
        "��֮�£������������ƴ����ڽ�������Ѱ�ѿ����뱱����ؤ���ͥ�����ˡ�ֻ�Ǻ�����\n"
        "Ȼ�����伣����֪�����ˡ�\n");
	set("gender", "����");
	set("age", 80);
    set("attitude", "peaceful");
	set("shen_type", 1);
        set("str", 45);
	set("int", 40);
	set("con", 48);
        set("dex", 44);
	
	set("max_qi", 6000);
	set("max_jing", 6000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 200);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("force", 250);
	set_skill("guiyuan-tunafa", 250);
	set_skill("dodge", 200);
	set_skill("shuishangpiao", 250);
	set_skill("strike", 250);
	set_skill("tiezhang-zhangfa", 300);
	set_skill("parry", 200);
	set_skill("literate", 100);
	set_skill("tiexue-hammer",250);
	set_skill("duanyun-fu", 250);
		
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

    create_family("���ư�", 13, "����");


	setup();
	carry_object(__DIR__"obj/black-cloth")->wear();
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") < 50000) {
                command("hehe");
                command("say ���Ϲٽ��Ͽɲ����ĵز���������ͽ�ܡ�");
                return;
        }
                command("say �ðɣ��Ҿ��������ˡ�ϣ������������񹦣���֮������");
                command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}

