//long.c
#include <ansi.h>
inherit NPC;

int ask_zhou();

void create()
{
        set_name("������", ( { "long daozhu", "long" }) );
        set("title", HIR"���͵�����"NOR);
        set("gender", "����" );
        set("age", 60);
        set("long",
              "���Ǹ���������ʮ����ĺ��ӣ���üȫ�棬��ɫ������һϮ���ۣ���Ȼͦ����\n"
        );

        set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);

        set("qi",4000);
        set("max_qi", 4000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 5000000);
        set("score", 250000);

        set_skill("force", 180);
        set_skill("taiji-shengong", 150);
        set_skill("dodge", 120);
        set_skill("tiyunzong", 100);
        set_skill("unarmed", 180);
        set_skill("taiji-quan", 150);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("taiji-jian", 160);
        set_skill("taoism", 200);
        set_skill("literate", 100);
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        set("chat_chance", 5);
        set("inquiry", ([
            "������" : (: ask_zhou :),
            "���͵�" :  "\n��������Һ�ľ�ֵ������з��ֵġ�\n",
        ]));
        set("chat_msg", ({
"��������Ȼһ���Դ���˵����������Ǻö����ۣ�\n",
"������˵������ô��ô���Ӣ��Ҳ��������̫�����ء�\n",
        }) );
        create_family("���͵�", 1, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( ob->query("combat_exp")< 10000)
              say ("������̧ͷ������һ�ۣ�˵����������ǳ��\n");
        return;
}

int ask_zhou()
{
        say("\n����������˵�����Ǳ������еĶ���������Ҫ��һζ'�ϳ����Ǹ��Ĳ�'���ɣ�\n"
"Ҫ������Ч�������������ֲ�ÿʮ��ſ�һ�λ������������������\n"
"һ���˺��ѵõ��ģ�С�ֵ���Ҫ��Ҫ�����Ե���ˣ�\n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obn;

        if (  ob->query("id") != "shane bu" && ob->query("id") != "fuxin cao")
        {
                message_vision("\n������ҡͷ�����ⲻ������Ҫ��ѽ��\n",who);
                return 0;
        }
        if ( ob->query("id") == "shane bu" )
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("������ҡͷ�����ҿ�С�ֵܽ����ڴ���Ե��\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("cao"))
                        {
                                message_vision("\n�������������Ʒ��񲾣���ϲ������ϲ��λС�ֵ���!\n",who);
                                obn=new("/d/xiakedao/obj/zhou");
                                obn->move(who);
                                delete_temp("bu");
                                delete_temp("cao");
                                return 1;
                        }
                        else if(query_temp("bu"))
                        {
                                message_vision("\n�������������Ʒ��񲾣���$Nҡͷ�������Ʒ��������ˡ�\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","�������������Ʒ��񲾣���ϲ��������ֻ��Ĳ��ˡ�\n",environment(who));
                                set_temp("bu",1);
                                return 1;
                        }
                }
        }
        if ( ob->query("id") == "fuxin cao")
        {
                if (random((int)who->query("kar")) <=25 )
                {
                        message_vision("������ҡͷ�����ҿ�С�ֵܽ����ڴ���Ե��\n",who);
                        return 1;
                }
                else
                {
                        remove_call_out("destroy");
                        call_out("destroy", 1, who, ob);

                        if(query_temp("bu"))
                        {
                                message_vision("\n���������Ǹ��Ĳݣ���ϲ������ϲ��λС�ֵ���!\n",who);
                                obn=new("/d/xiakedao/obj/zhou");
                                obn->move(who);
                                delete_temp("cao");
                                delete_temp("bu");
                                return 1;
                        }
                        else if(query_temp("cao"))
                        {
                                message_vision("\n���������Ǹ��Ĳݣ���$Nҡͷ�������Ĳ����Ѿ����ˡ�\n",who);
                                return 0;
                        }
                        else
                        {
                                message("vision","�������������Ĳݣ���ϲ��������ֻ�����Ʒ����ˡ�\n",environment(who));
                                set_temp("cao",1);
                                return 1;
                        }
                }
        }
        return 1;
}

int recognize_apprentice(object ob)
{

    message_vision("$Nҡ��ҡͷ��\n",this_object());
    command("tell "+ob->query("id")+"���ǲ��յ��ӵģ�����Ե�ʯ������ѧ�ۣ� \n");
    return 0;

}

int do_skills(string arg)
{
        object ob ;
        ob = this_player () ;
        if( !arg || arg!="long" )
                return 0;
        if(wizardp(ob))
                return 0;
        if (ob->query("weiwang") <50 )
        {
        message_vision("$Nҡ��ҡͷ��\n",this_object());
        write("������˵��������ô�ܿ��ҵ��书�أ�\n");
        return 1;
        }
        command("tell "+ob->query("id")+" �����е��书���£�\n"+
"  �����Ṧ (dodge)                         - һ����ʦ  100/    \n"+
"  �����ڹ� (force)                         - һ����ʦ  100/    \n"+
"  ����д�� (literate)                      - һ����ʦ  100/    \n"+
"  �����м� (parry)                         - һ����ʦ  100/    \n"+
"  �������� (sword)                         - һ����ʦ  100/    \n"+
"��̫������ (taiji-jian)                    - ��ɲ�  200/    \n"+
"��̫��ȭ (taiji-quan)                      - �Ƿ��켫  150/    \n"+
"��̫���� (taiji-shengong)                - �Ƿ��켫  150/    \n"+
"  ��ѧ�ķ� (taoism)                        - ��ɲ�  200/    \n"+
"�������� (tiyunzong)                       - �Ƿ��켫  100/    \n"+
"  ����ȭ�� (unarmed)                       - һ����ʦ  100/    \n");
        return 1;
}
