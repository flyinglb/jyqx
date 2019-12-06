                 // chen.c

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
        set_name("陈有德", ({ "chen youde", "chen" }));
        set("long", "陈有德是扬州武馆馆长。\n");
        set("gender", "男性");
        set("age", 45);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("claw", 80);
        set_skill("hand", 80);
        set_skill("strike", 80);
        set_skill("finger", 80);
        set_skill("cuff", 80);
        set_skill("blade", 80);
        set_skill("stick", 80);
        set_skill("club", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("throwing", 80);
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
        me->set_temp("marke/chenyoude_tong_ren", 1);
        write("陈有德对你说道：铜人是用一位高人所留的图纸做成的，10 两黄金，不二价！\n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obj;
        if ( ob->query("money_id") && ob->value() >= 100000 ) {
                if(!who->query_temp("marke/chenyoude_tong_ren")) {
                        message_vision("陈有德对$N说：陈某向来不功不受禄，你给我这么多钱干什么？\n" , who);
                        return 0;
                }
                who->delete_temp("marks/chenyoude_tong_ren");
                obj = new("/d/npc/obj/tong-box");
                obj->set("buy_master", who->query("id"));
                
                if(!obj->move(who)) obj->move(environment(who));
                
                message_vision("陈有德对$N说：喏，这就是了，可要小心使用啊！\n" , who);
//                command("whisper "+who->query("id")+" 这玩意必须先得打开(open)，用完了记得收(shou)起来。")
                command("whisper "+who->query("id")+" 这玩意必须先得打开(open)。");
                    call_out("destroy",1,ob);
                return 1;
        }
        if (who->query("combat_exp")>= 3500) {
                message_vision("陈有德望着$N说：你的武功应该历练江湖才能再长进，不能埋没在这里了。\n", who);
                return 0;
        }
        if (ob->query("money_id") && ob->value() >= 500) {
                who->set_temp("marks/yangzhou_paied",1);
                message_vision("陈有德对$N说：好！这位" + RANK_D->query_respect(who) + "想学什么呢？\n" , who);
                return 1;
        } else
                message_vision("陈有德皱眉对$N说：钱我不在乎。可你也给的也太少了点儿吧？\n", who);
                return 0;
        }

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/yangzhou_paied")==1) return 0;
        return 1;
}
