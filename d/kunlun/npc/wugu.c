inherit NPC;
string ask_book();
void create()
{
        set_name("五姑", ({ "wu gu" }));
        set("gender", "女性");
        set("age", 27);
        
        set("qi", 200);
        set("max_qi", 200);
        set("jing", 200);
        set("max_jing", 200);

        set("combat_exp", 300);
        set("attitude", "peaceful");

        set("chat_chance", 3);
        set("chat_msg", ({
                (: command("say 妾身这救命之恩，该如何报答呢？") :),
        }) );

        set("inquiry", ([
                "报答" : (: ask_book :),
        ]));
        set("chessbook_count",8-random(10));
        setup();
        carry_object("/clone/cloth/female2-cloth")->wear();
}
string ask_book()
{
        object me;
        object ob;
        me = this_player();
        if( !me->query_temp("kunlun/help_wugu") ) {
                return "救我的人怎么会是你？别当我什么都不知道。\n";
        }
        if (query("chessbook_count") < 1) 
                return "多谢救命之恩，此刻我这里什么也没有，容以后再回报吧。";
        add("chessbook_count", -1);
        ob = new(__DIR__"obj/chessbook");
        ob->move(me);
        me->delete_temp("kunlun/help_wugu");
        return "多谢救命之恩，这里有本初级围棋教材就送给你吧。";
        delete("chat_msg");
        delete("chat_chance");
}
