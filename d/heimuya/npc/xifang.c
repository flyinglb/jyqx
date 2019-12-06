#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("����ʧ��", ({"xifang shibai", "xifang"}));
    set("nickname", HIY "�����޵�" NOR );
    set("gender", "Ů��");
    set("age", 42);
    set("long",
        "������������̽������ų����˿ɵУ������һ�ƺ�Ϊ������ʧ�ܡ���\n");
    set("attitude", "peaceful");

    set("str", 31);
    set("int", 10);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
 "����ʧ��̾�˿����������� ���� �Ƕ���������˭ѽ�����Ƿ���������\n",
        }));
    set("inquiry", ([
        "����ͤ"   : "���ֱ���Ұ��˵�����,������ѽ�� \n",
        "��������" : "������ܰ���ȡ�ÿ��������ϲᣬ��һ������л�㡣\n",
    ]));

    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 20);

    set("combat_exp", 250000);
    set("score", 0);

    set_skill("force", 100);             // �����ڹ�
    set_skill("finger", 100);            // ����ָ��
    set_skill("tanzhi-shentong", 100);   // ��ָ��ͨ
    set_skill("dodge", 100);             // ��������
    set_skill("anying-fuxiang", 100);    // ��Ӱ����
    set_skill("parry", 100);             // �����м�
    set_skill("sword", 100);             // ��������
    set_skill("pixie-jian", 80);        // PiXieJian
    set_skill("qimen-wuxing",100);       // ��������
    set_skill("literate",100);           // ����ʶ��
    set_skill("kuihua-xinfa", 100);       // �����ķ�

    map_skill("force"  , "kuihua-xinfa");
    map_skill("sword", "pixie-jian");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "pixie-jian");

    create_family("�������", 2, "����");

    setup();
    carry_object(__DIR__"obj/zhen")->wield();
    carry_object(__DIR__"obj/hongchouxiaoshan")->wear();

}

void attempt_apprentice(object ob)
{
    if (ob->query_int() < 20) {
        command("say �Ҳ������ʲ�ĵ��ӣ�����ذɣ�\n");
                return;
    }
   
    command("say �ܺã��ܺá�\n");
    command("recruit " + ob->query("id"));
}
int recognize_apprentice(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if ( myfam["family_name"] == "��ľ��") return 1 ;
        if ((int)ob->query_temp("tmark/��") == 1 )
        message_vision("�������ܿ��˿�$N��˵��������������˭Ҳ��Ƿ˭,\n"
                          "�㲻Ҫ������ѧϰ�����ˡ�\n", ob);
        if (!(int)ob->query_temp("tmark/��"))
                return 0;
        ob->add_temp("tmark/��", -1);
        return 1;
}



int accept_object(object who, object ob)
{

        if ( (string) ob->query("id") =="kuihua baodian1" ) {
                if (!(int)who->query_temp("tmark/��",)) who->set_temp("tmark/��",100);
                message_vision("�������ܿ��˿�$N�������ؼ������˵�ͷ��˵����\n"
                               "�ѵ��㽫�����ͻء������ҵĶ����Ҿ������ˡ�\n"
                               "��Ϊ����,����Դ�������ѧ�㹦��\n", who);
                who->add_temp("tmark/��", 100);
                return 1;

        }
        return 0;
}
