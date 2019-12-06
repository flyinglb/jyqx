inherit NPC;
string ask_book();
void create()
{
        set_name("���", ({ "wu gu" }));
        set("gender", "Ů��");
        set("age", 27);
        
        set("qi", 200);
        set("max_qi", 200);
        set("jing", 200);
        set("max_jing", 200);

        set("combat_exp", 300);
        set("attitude", "peaceful");

        set("chat_chance", 3);
        set("chat_msg", ({
                (: command("say ��������֮��������α����أ�") :),
        }) );

        set("inquiry", ([
                "����" : (: ask_book :),
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
                return "���ҵ�����ô�����㣿����ʲô����֪����\n";
        }
        if (query("chessbook_count") < 1) 
                return "��л����֮�����˿�������ʲôҲû�У����Ժ��ٻر��ɡ�";
        add("chessbook_count", -1);
        ob = new(__DIR__"obj/chessbook");
        ob->move(me);
        me->delete_temp("kunlun/help_wugu");
        return "��л����֮���������б�����Χ��̲ľ��͸���ɡ�";
        delete("chat_msg");
        delete("chat_chance");
}
