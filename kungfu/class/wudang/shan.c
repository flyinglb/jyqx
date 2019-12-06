// shan.c �Ŵ�ɽ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�Ŵ�ɽ", ({ "zhang cuishan", "zhang" }));
        set("nickname", "�䵱����");
        set("long",
                "�������������������ĵ��ӡ��䵱����֮����Ŵ�ɽ��\n"
                "��һ���ɸɾ������಼������\n"
                "��������ʮ��ͷ��ͣ�����Ӣ����һ������������ͷ��\n");
        set("gender", "����");
        set("age", 25);
        set("attitude", "peaceful");
        set("class", "scholar");
        set("shen_type", 1);
        set("no_get", "1");
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 2000);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 60000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
        }) );
        set_skill("force", 100);
        set_skill("taiji-shengong", 100);
        set_skill("dodge", 100);
        set_skill("tiyunzong", 100);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("liangyi-jian", 100);
        set_skill("taiji-jian", 100);
        set_skill("literate", 100);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
	set("chat_chance", 20);
        set("chat_msg", ({
            "�Ŵ�ɽ��ݺݵ�˵����û������ˢ�ӣ��Ҹ����⽣�ң�\n",
            "�Ŵ�ɽ����̾�����ĸ���ʦ�����ҵ����أ�����Ѽׯһ�١�\n"
        }));

        create_family("�䵱��", 2, "����");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}

void greeting(object ob)
{
        object where;
        object me = this_player();
	where = environment(me);
        
        if( environment(ob) != environment() ) return;
	if ((string)where->query("short")=="�⽣��")
                {if ((int)ob->query("shen") < 0)
                        {
                        say(CYN"\n\n�Ŵ�ɽ����ŭ�ݣ���аħ��������˱��ӵ��ˣ���ǿ���䵱����\n\n");
                        message_vision("�Ŵ�ɽ�Ӹ����£�����һ�ƣ�$Nֻ��Ӳ�ӣ����ӻ���һ�¡�\n",ob);
                        message_vision("�Է����ֳ����漴�ݳ���$N�޷��мܣ�����һ����\n\n\n"NOR,ob);
                        ob->move("/d/wudang/slxl2");
                        }
                }
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
        if (ob->query_int() < 30)
        {
                command("say ������ʽ������������������ľ��磬����Ҳ�ǰ״\n");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + ob->query("id"));
}
