// yan.c �����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "yu daiyan", "yu" }));
        set("nickname", "�䵱����");
        set("long",
                "���������������ҵĵ��ӡ��䵱����֮��������ҡ�\n"
                "��һ���ɸɾ������಼������\n"
                "��������ʮ��ͷ��ͣ�˫�Ȳзϣ������������������佣��\n");
        set("gender", "����");
        set("age", 31);
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("jiali", 50);
        set("combat_exp", 250000);
        set("score", 60000);

        set_skill("force", 100);
        set_skill("taiji-shengong", 100);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 50);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
	set("chat_chance", 1);

        set("chat_msg", ({
            "�����˵�������佣���Ƕ�ʦ����Ѫ��",
            "���������̾������λ��ʦ���κ��ҵ��ȣ���Ҳ��Ѽׯһ�١�"
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
   if (((int)ob->query_skill("taiji-shengong", 1) == 0))
   {
      message_vision(CYN"ʮ�����Ӷ�$N�����ȵ��������аħ������������佣��\n\n"NOR,ob);
      ob->set("qi",30);
      if ((int)ob->query("combat_exp") <2000) ob->set("combat_exp",1);
         else ob->add("combat_exp",-1000);
      message_vision(CYN"���佣���ʱ��������̨�Ͻ����ݺᣬ��$NΧ�����롣\n"NOR,ob);
      message_vision(CYN"ʮ���ڳ����������$N���ϻ�����ʮ�������ӣ���Ѫ���졣\n"NOR,ob);
      say(CYN"\n\n���������ŭ�ݣ���аħ�����Ҳ�Ҵ����佣�󣡡�\n");
      message_vision("����ҾӸ����£�����һ�ư�$N�����̨��\n\n\n"NOR,ob);
      ob->move("/d/wudang/nanyangong");
      CHANNEL_D->do_channel(this_object(),"chat",sprintf("%s ˽�����佣������ɳ����ף�����һ����",ob->name(1)));
   }
}

void attempt_apprentice(object me)
{
        if ((int)me->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(me) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
        if ((int)me->query("guarded") < 15) {
                command("say " + RANK_D->query_respect(me) +
                        "�������䵱���£��㻹��Ҫ���Ŭ�����ĲŶԡ�");
                return;
        }

        if ((int)me->query_skill("taiji-shengong", 1) < 30) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(me) +
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }
        if ((int)me->query("shen") < 1000) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(me) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + me->query("id"));
}
