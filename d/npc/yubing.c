//jyqxII 名人堂
// by sdlkx 2001-8-11 10:06

#include <ansi.h>

inherit NPC;

int ask_sdlkx();

void create()
{
        set_name(HIM"玉冰"NOR,({"Yubing"}));
        set("per",(int)random(5)+30);
        set("nickname",HIC"〖"HIR"血影门"HIC"〗"HIM"圣剑堂·堂主"NOR);
        set("gender", "女性");
        set("age", 20);
        set("long",
                "她是这里最好的玩家。\n" // 老婆自己改吧，呵呵
        );
        set("inquiry", ([
                "sdlkx": "他是我老公啊。\n",
                "一点红": (:ask_sdlkx:),
        ]));
        setup();
        carry_object("/d/city2/obj/jinduan")->wear();
}

int ask_sdlkx()
{
        object ob;
        
        ob=this_player();
        
        if (ob->query("gender")!="男性")
         {
                command("say " + ob->query("name") + "，你问这个做什么？！");
                command("? " + ob->query("id"));
         }
        else
         {
                if (ob->query("id")=="sdlkx"){
                        command("say 老公，你干什么啊！怎么自已问自已？");
                        return 1;}
                command("say " + ob->query("name") + "，你找他有事啊，他就在那边。");
                command("shzi " + "sdlkx");
         }
        return 1;
}

