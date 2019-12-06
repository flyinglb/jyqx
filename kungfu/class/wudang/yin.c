// yin.c ����ͤ
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����ͤ", ({ "yin liting","yin"}));
        set("nickname", "�䵱����");
        set("long",
                "��������������������ĵ��ӡ��䵱����֮��������ͤ��\n"
                "��һ���ɸɾ������಼������\n"
                "��������ʮ��ͷ��ͣ������ܸɣ�������������һ�ȴһֱһ�������ı��顣\n");
        set("gender", "����");
        set("age", 23);
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("shen_type", 1);
        set("str", 26);
        set("int", 39);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("jiali", 50);
        set("combat_exp", 250000);
        set("score", 60000);

        set_skill("force", 95);
        set_skill("taiji-shengong", 100);
        set_skill("dodge", 95);
        set_skill("tiyunzong", 100);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("liangyi-jian", 100);
        set_skill("literate", 95);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");

        create_family("�䵱��", 2, "����");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
        if ((int)ob->query("guarded") < 15) {
                command("say " + RANK_D->query_respect(ob) +
                        "�������䵱���£��㻹��Ҫ���Ŭ�����ĲŶԡ�");
                return;
        }
        if ((int)ob->query_skill("taiji-shengong", 1) < 40) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }
        if ((int)ob->query("shen") < 1000) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
