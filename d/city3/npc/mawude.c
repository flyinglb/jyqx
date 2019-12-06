              // mawude.c

inherit NPC;
#include <ansi.h>
int ask_me();
void destroy(object obj)
{
        if(!obj) return;
        obj->move(VOID_OB);
        destruct(obj);
}

void create()
{
        set_name("马五德", ({ "ma wude", "ma" }));
        set("title","金牛武馆馆长");
        set("long", "马老爷子是武馆的缔造者，辛苦一辈子了，仍勇于提携后生。\n");
        set("gender", "男性");
        set("age", 65);

        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("hand", 80);
        set_skill("blade", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
                "铜人" : (: ask_me :),
        ]));

        setup();

}

int ask_me()
{
        object me = this_player();
        me->set_temp("marke/mawude_tong_ren", 1);
        write("马五德对你说道：铜人是用一位高人所留的图纸做成的，10 两黄金，不二价！\n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obj;
        if ( ob->query("money_id") && ob->value() >= 100000 ) {
                if( !who->query_temp("marke/mawude_tong_ren") ) {
                        message_vision("马五德对$N说：马某向来不功不受禄，你给我这么多钱干什么？\n" , who);
                        return 0;
                }
                who->delete_temp("marks/mawude_tong_ren");
                obj = new("/d/npc/obj/tong-box");
                obj->set("buy_master", who->query("id"));
                
                if(!obj->move(who)) obj->move(environment(who));
                
                message_vision("马五德对$N说：喏，这就是了，可要小心使用啊！\n" , who);
                //command("whisper "+who->query("id")+" 这玩意必须先得打开(open)，用完了记得收起(shou)来。");
                command("whisper "+who->query("id")+" 这玩意必须先得打开(open)。");
                    call_out("destroy",1,ob);
                return 1;
        } else
                return 0;
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/jinniu_paied")==1) return 0;
        return 1;
}
