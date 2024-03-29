// goudu.c
// edward 2000.3

inherit NPC;
//inherit F_MASTER;

#include <ansi.h>

string ask_me();

void create()
{
        set_name(HIC"苟读"NOR, ({ "gou du", "gou" }));
        set("long", 
                "他看上去也是几十岁的人了，却是纯然一个书呆子的模样。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "friendly");
        set("class", "scholar");
        set("shen_type", 1);
        set("str", 25);
        set("int", 35);
        set("con", 25);
        set("dex", 25);

        set("inquiry", ([
                "论语":(:ask_me:),
        ]) );

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 60);
        set("combat_exp", 150000);
        set("score", 40000);

        set_skill("blade",70);
        set_skill("ruyi-dao",70);
        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
        set_skill("parry", 70);
        set_skill("lingboweibu", 70);
        set_skill("beiming-shengong",70);
        set_skill("zhemei-shou", 70);
        set_skill("literate", 150);

        map_skill("unarmed", "zhemei-shou");
        map_skill("dodge", "lingboweibu");
        map_skill("force", "beiming-shengong");
        map_skill("blade", "ruyi-dao");

        set("book_count", 1);

        create_family("逍遥派", 3, "弟子");
        set("title","逍遥派"MAG"“函谷八友”"NOR);
        set("nickname",HIY"书呆"NOR);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/blade")->wield();

}


string ask_me()
{
        object me,ob;
        ob=this_player(); 

        if (query("book_count") < 1)
                return "你来晚了，那本"HIY"《论语》"NOR"我已经赠送给别入了。";   
        add("book_count", -1);                  

        if(ob->query("family/master_id")=="xiaoyao zi")
        {
                command("say 师叔想要"HIY"《论语》"NOR"，拿去就是。");
                message_vision(HIY"苟读从怀里掏出一本"MAG"旧书"NOR"，交了给$N \n\n"NOR,ob);
                me=new("/clone/book/lbook4");
                me->move(ob);
                return RED"这本书可千万不要借给别人啊，他们一借就不还的了。\n"NOR;
        }
        command("say 哈哈，"HIY"《论语》"NOR"就没有了，这里有我派高手从少林盗来的书。");
        command("say 既然你那么好学，我就把它送给你吧。\n");
        message_vision(HIY"苟读翻箱倒柜找了半天，找出一本"MAG"旧书"HIY"，交了给$N \n\n"NOR,ob);
        if (random(2) == 1) me=new("/clone/book/strike_book");
        else me=new("/clone/book/book-paper");
        me->move(ob);

        return RED"这本书可千万不要借给别人啊，他们一借就不还的了。\n"NOR;
}

