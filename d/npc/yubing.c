//jyqxII ������
// by sdlkx 2001-8-11 10:06

#include <ansi.h>

inherit NPC;

int ask_sdlkx();

void create()
{
        set_name(HIM"���"NOR,({"Yubing"}));
        set("per",(int)random(5)+30);
        set("nickname",HIC"��"HIR"ѪӰ��"HIC"��"HIM"ʥ���á�����"NOR);
        set("gender", "Ů��");
        set("age", 20);
        set("long",
                "����������õ���ҡ�\n" // �����Լ��İɣ��Ǻ�
        );
        set("inquiry", ([
                "sdlkx": "�������Ϲ�����\n",
                "һ���": (:ask_sdlkx:),
        ]));
        setup();
        carry_object("/d/city2/obj/jinduan")->wear();
}

int ask_sdlkx()
{
        object ob;
        
        ob=this_player();
        
        if (ob->query("gender")!="����")
         {
                command("say " + ob->query("name") + "�����������ʲô����");
                command("? " + ob->query("id"));
         }
        else
         {
                if (ob->query("id")=="sdlkx"){
                        command("say �Ϲ������ʲô������ô���������ѣ�");
                        return 1;}
                command("say " + ob->query("name") + "�����������°����������Ǳߡ�");
                command("shzi " + "sdlkx");
         }
        return 1;
}

