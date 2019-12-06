// qqren.c ��ǧ��

inherit NPC;
int ask_qiubai();
inherit F_MASTER;

void create()
{
    set_name("��ǧ��", ({ "qiu qianren", "qiu", "qianren", "ren"}));
    set("nickname", "����ˮ��Ư");
	set("long", 
        "����������������ư�İ���-����ˮ��Ư��ǧ��\n"
        "����һ��������ͷ�����Ƹ���������ֻ���һ�Ѵ����ȡ�\n");
	set("gender", "����");
	set("age", 60);
    set("attitude", "peaceful");
	set("shen_type", -1);
        set("str", 35);
	set("int", 30);
	set("con", 28);
        set("dex", 35);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 200);
	set("combat_exp", 1000000);
	set("score", 400000);
	set_skill("hammer",100);
	set_skill("tiexue-hammer",180);
	set_skill("force", 160);
	set_skill("guiyuan-tunafa", 200);
	set_skill("dodge", 160);
	set_skill("shuishangpiao", 200);
	set_skill("strike", 180);
	set_skill("tiezhang-zhangfa", 200);
	set_skill("parry", 160);
	set_skill("literate", 100);
	set_skill("axe", 160);
	set_skill("duanyun-fu", 200);
	map_skill("hammer", "tiexue-hammer");

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
        map_skill("axe", "duanyu-fu");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

    create_family("���ư�", 14, "����");

    set("inquiry", ([
"name" : "�Ϸ���ǡ�����ˮ��Ư����ǧ�������Ϸ�������ʲô��ô��\n",
"here" : "����������ư����̳���ڣ�����û�£���Ҫ�Ĵ����ߣ�����ɱ��֮��������\n",
"�Ϲٽ���" : (: ask_qiubai :),
    ]));

	setup();
	carry_object(__DIR__"obj/black-cloth")->wear();
        carry_object(__DIR__"obj/hammer")->wield();
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -10000) {
                command("hehe");
                command("say ����ǧ��ɲ����Ĵ����������ͽ�ܡ�");
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
int ask_qiubai()
{
say("������ʦ��������ʮ�����������ȹ�����֮�����ж�ͼ������ȫ\n"
    "���书�������ܡ���ϧʮ��ǰ�����ں�������Χ������������\n");
return 1;
}

