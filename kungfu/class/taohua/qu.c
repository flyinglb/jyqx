// qu.c
#include <command.h>
#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name( "�����" ,({ "qu lingfeng", "qu" }));
        set("gender", "����");
        set("age", 46);
        set("long",
            "������ǻ�ҩʦ�Ĵ�ͽ�ܣ�Ҳ�ǻ�ҩʦ������ͽ�������Ի�ҩʦһ��\n"
            "���Ĺ������������Ը�Ź֣�������ʦ����а����\n"
            "�������޳�����òӢ��������ƮƮ������������\n");
        set("attitude", "peaceful");
        set("class", "scholar");
        set("str", 30);
        set("int", 40);
        set("con", 35);
        set("dex", 25);
        set("chat_chance", 1);
        set("chat_msg", ({
            "�����˵������ʦ���۰�Сʦ�ã�������⬼�һֱ��Сʦ�ô��š���\n",
            "��������������˵����������һ����ˣ����򵥣���\n",
        }));
        set("max_qi",1800);
        set("max_jing",500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        set("shen_type",0);

        set("combat_exp", 500000);
        set_skill("force", 100);             // �����ڹ�
        set_skill("bibo-shengong", 100);     // �̲���
        set_skill("unarmed", 100);           // ����ȭ��
        set_skill("xuanfeng-leg", 100);      // ����ɨҶ��
        set_skill("strike", 100);            // �����Ʒ�
        set_skill("luoying-zhang", 100);     // ��Ӣ����
        set_skill("dodge", 100);             // ��������
        set_skill("anying-fuxiang", 100);    // ��Ӱ����
        set_skill("parry", 100);             // �����м�
        set_skill("sword", 100);             // ��������
        set_skill("luoying-shenjian", 100);  // ��Ӣ��
        set_skill("qimen-wuxing",50);       // ��������
        set_skill("literate", 100);          // ����ʶ��

        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "xuanfeng-leg");
        map_skill("strike" , "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-shenjian");
        map_skill("sword"  , "luoying-shenjian");

        create_family("�һ���", 2, "����");

        set("inquiry", ([
           "�һ���":   "��������һ������������Ǳ��ɵ��ӣ�Ҫ���һ���",
           "�һ���":   "���Ͼ����ˡ�",
           "��а":     "��ʦ�˳ƶ�а���Ǻǡ�",
           "����":     "ŷ���������ʦ���������ĸ��֣��˳��϶��",
           "�ϵ�":     "����ʦ˵����ү���ڳ��ҵ��˺��У�����һ�ơ�",
           "��ؤ":     "��ؤ���߹���ؤ��������������ݳ��⡣",
           "����":     "����ʦ���İ�Ů��",
           "��ҩʦ":   "��Ҫ�ݷü�ʦ��"
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
    if (ob->query_dex() < 20)
    {
       command("say �����书���������ɽݡ�");
       command("say ��λ"+RANK_D->query_respect(ob)+"�����ǰ����һ���һ���ˡ�");
       return;
    }
    if ((int)ob->query("shen") < 1)
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
    if (ob->query_skill("bibo-shengong",1) <= 30)
    {
       command("say ����һ���֮ǰûȥ��½ʦ���Ƕ�ô��");
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
    return 1;
}

