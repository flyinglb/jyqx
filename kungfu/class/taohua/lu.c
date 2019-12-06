// lu.c
#include <command.h>
#include <ansi.h>
inherit NPC;                                                                    
inherit F_MASTER;                                                               
void create()
{
        set_name( "½�˷�" ,({ "lu chengfeng", "lu" }));
        set("gender", "����");
        set("age", 52);
        set("long",
            "½�˷��ǻ�ҩʦ�ĵ��ĸ�ͽ�ܡ�\n"
            "�����޽���΢���׷��������Ŀ��࣬˫������\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 28);
        set("con", 30);
        set("dex", 30);
        set("chat_chance", 1);
        set("max_qi",1500);
        set("max_jing",500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        set("shen_type",1);

        set("combat_exp", 300000);
        set_skill("force", 90);             // �����ڹ�
        set_skill("bibo-shengong", 80);     // �̲���
        set_skill("unarmed", 90);           // ����ȭ��
        set_skill("xuanfeng-leg", 90);      // ����ɨҶ��
        set_skill("strike", 90);            // �����Ʒ�
        set_skill("luoying-zhang", 90);     // ��Ӣ����
        set_skill("dodge", 70);             // ��������
        set_skill("anying-fuxiang", 70);    // ��Ӱ����
        set_skill("parry", 90);             // �����м�
        set_skill("sword", 90);             // ��������
        set_skill("luoying-shenjian", 90);  // ��Ӣ��
        set_skill("literate",90);           // ����ʶ��

        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "xuanfeng-leg");
        map_skill("strike" , "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-shenjian");
        map_skill("sword"  , "luoying-shenjian");

        set("jinbing", 10);
        create_family("�һ���", 2, "���� ����ׯ��");

        set("inquiry", ([
           "�һ���":   "��������һ������������Ǳ��ɵ��ӣ�Ҫ���һ���",
           "�һ���":   "���Ͼ����ˡ�",
           "��а":     "��ʦ�˳ƶ�а���Ǻǡ�",
           "����":     "ŷ���������ʦ���������ĸ��֣��˳��϶��",
           "�ϵ�":     "����ʦ˵����ү���ڳ��ҵ��˺��У�����һ�ơ�",
           "��ؤ":     "��ؤ���߹���ؤ��������������ݳ��⡣",
           "����":     "����ʦ���İ�Ů��",
           "��ҩʦ":   "��Ҫ�ݷü�ʦ��"
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
        if (ob->query_dex() < 20)
        {
           command("say �����书���������ɽݡ�");
           command("say ��λ"+RANK_D->query_respect(ob)+"�����ǰ�������ׯһ���ˡ�");
           return;
        }
        if ((int)ob->query("shen") < 0)
        {
           command("say �����ڽ���������������"+ RANK_D->query_respect(ob)+"��ذɡ�");
           return;
        }
        if (ob->query("gender") == "����")
        {
           command("say ʦ�������᲻�в�Ů�Ķ����ˣ���λ"+RANK_D->query_respect(ob)+"�Ͽ���ɡ�");
           return;
        }
        if (ob->query("class") == "bonze")
        {
           command("say ʦ�����ɮ�ֵ��ˣ���λ"+RANK_D->query_respect(ob)+"������ذɡ�");
           return;
        }
        if (ob->query_skill("literate",1) <= 10)
        {
           command("say �һ���ֻ�ն����������ӣ���λ"+RANK_D->query_respect(ob)+"�Ƿ�ȥ������������");
           return;
        }
        command("smile");
        command("say " + RANK_D->query_respect(ob) + "�������£���Ŭ�����顣");
        command("recruit " + ob->query("id"));
}
int accept_fight(object ob)
{
        command("wield jian");
}
int accept_object(object who, object ob)
{
	int exp;
	if (query("jinbing") < 0)
	{
                command("say " + RANK_D->query_respect(who) + "�Һ��ۣ����ͷ�������Ͱɡ�");
		return 0;
	}
	if (strsrch(ob->query("name"), "���տ���ͷ­") < 0 &&
	    strsrch(ob->query("name"), "���պ��ҵ�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "ŷ�����ͷ­") < 0 &&
	    strsrch(ob->query("name"), "ŷ���˵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "��������ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�����̵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�������˵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "ɳͨ���ͷ­") < 0 &&
	    strsrch(ob->query("name"), "��ͨ����ͷ­") < 0 &&
	    strsrch(ob->query("name"), "����յ�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�����ҵ�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "�����۵�ͷ­") < 0 &&
	    strsrch(ob->query("name"), "Ǯ�ཡ��ͷ­") < 0 &&
	    strsrch(ob->query("name"), "������ͷ­") < 0 &&
	    strsrch(ob->query("name"), "����µ�ͷ­") < 0) 
	{
                command("say ������Щ������ʲô�ã�\n");
		return 0;
	}
	else
	{
                command("say ������������һֱ��ɱ��Щ�𹷣�л������ˡ�");
	}
	exp = 20+random(30);
	add("jinbing", -1);
	tell_object(who,HIW"½�˷罱������\n"+chinese_number(exp)+"��ʵս����\n"NOR);
	return 1;
}