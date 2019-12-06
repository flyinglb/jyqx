// feng.c
#include <command.h>
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()                                                                   
{
        set_name( "��Ĭ��" ,({ "feng mofeng", "feng" }));
        set("gender", "����");
        set("age", 39);
        set("long",
            "��Ĭ���ǻ�ҩʦ��С��һ��ͽ�ܣ����ĸ������������ӽ�Ϊ��³��\n"
            "���Ļ�������ʵ��һ���Һ���ʵ�����ӡ�\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 29);
        set("con", 35);
        set("dex", 25);
        set("chat_chance", 1);
        set("chat_msg", ({
            "��Ĭ��˵������ʦ���۰�Сʦ�ã�������⬼�һֱ��Сʦ�ô��š���\n",
            "��Ĭ�����������˵����������һ����ˣ����򵥣���\n",
        }));
        set("max_qi",1000);
        set("max_jing",500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("shen_type",1);
        set("combat_exp", 200000);
        set_skill("force", 70);             // �����ڹ�
        set_skill("bibo-shengong", 60);     // �̲���
        set_skill("unarmed", 60);           // ����ȭ��
        set_skill("xuanfeng-leg", 50);      // ����ɨҶ��
        set_skill("strike", 60);            // �����Ʒ�
        set_skill("luoying-zhang", 50);     // ��Ӣ����
        set_skill("dodge", 50);             // ��������
        set_skill("anying-fuxiang", 50);    // ��Ӱ����
        set_skill("parry", 70);             // �����м�
        set_skill("sword", 70);             // ��������
        set_skill("luoying-shenjian", 70);  // ��Ӣ��
        set_skill("literate",50);           // ����ʶ��

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
       command("say ��λ"+RANK_D->query_respect(ob)+"�����ǰ����һ���һ���ˡ�");
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
}
