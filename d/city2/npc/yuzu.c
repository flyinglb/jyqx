// yuzu.c
#include <ansi.h>;
#include <command.h>;
inherit NPC;
void create()
{
        set_name("�̲�����", ({ "yu zu","zu" }) );
        set("title", HIR"��Ʒ"HIB"��������"NOR);
        set("gender", "����" );
        set("age", 32);
        set("str", 22);
        set("con", 25);
        set("dex", 20);
        set("int", 30);
        set("long",
"���ӽ��±����ǵ��̲��춥���䣬�������⣬��ݿ������㿴��ҪС���ˡ�\n");
        set("combat_exp", 2000000);
        set("attitude", "heroism");

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("max_neili", 2000);
        set("neili", 2000);
        set("jiali", 100);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("blade", 200);

        set("inquiry", ([
        "����"   : "�ٺٺٺ٣����������ûʥ�ϵ�ּ�⣬����ûָ��ඡ�\n",
        ]) );
        setup();

        carry_object("/d/city/obj/yayifu")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_chat","chat");
        add_action("do_chat","rumor");
        add_action("do_chat","party");
        add_action("do_chat","xkx");
        add_action("do_chat","sing");
        add_action("do_chat","to");
        add_action("do_chat","chat*");
        add_action("do_chat","tell");
        add_action("do_chat","reply");
        add_action("do_chat","exert");
        add_action("do_chat","yun");
        add_action("do_chat","dazuo");
        add_action("do_chat","exercise");
        add_action("do_chat","tuna");
        add_action("do_chat","meditate");
        add_action("do_chat","lian");
        add_action("do_chat","practice");
        add_action("do_chat","du");
        add_action("do_chat","study");
        add_action("do_chat","xue");
        add_action("do_chat","learn");
        add_action("do_chat","vote");
        add_action("do_chat","finger");
        add_action("do_chat","suicide");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        command("rumor ������" + ob->query("name")
                + "�ѱ��̲����������ù鰸��\n");
        ob->set("startroom","/d/city2/jail");
}

int do_chat(string arg)
{
        object ob = this_player();
        switch(random(3))
        {
            case 1:
        command("say "+ob->query("name")+"������ٶ�һ�����ٶ��͸���һͰ����\n");
                  break;
            case 2:
        command("say "+ob->query("name")+"������Ƥ���������ﲻˬ��\n");
        message_vision(HIR"�̲�������ͷ���Ծ���һ��Ƥ�ޣ����$NƤ���������ò���ˬ��\n"NOR,ob);
                  ob -> receive_damage("qi",10);
                  break;
            default:
        command("say "+this_player()->query("name")+"�����ǲ��Ǿ�������������࿪�ļ��죿\n");
                  break;
        }
        return 0;
}
