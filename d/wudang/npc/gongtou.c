#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
void create()
{
        set_name("工头", ({"gong tou", "gongtou", "gong", "tou"}));
        set("gender", "男性");
        set("age", 40);
        set("long", "这是一个四十岁左右的工头，长着一脸横肉。\n");
        set("attitude", "peaceful");             
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("neili", 120);
        set("max_neili", 120);
        set("jiali", 0);
        
        set("combat_exp", 5500);
        set("score", 200);
        
        set_skill("force", 10); 
        set_skill("unarmed", 10); 
        set_skill("dodge", 10); 
        set_skill("parry", 10);          

        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "job" : (: do_gongzuo :),
        ]) );

        setup();
        carry_object("clone/cloth/cloth")->wear();
}

int do_gongzuo()
{      
        object me;
        int pot;
        me = this_player(); 
        if( me->query_temp("gongzuo/famu") == 1 ) {
                tell_object(me,"你怎麽又回来了，快去。\n");
                return 1;
        }  
        pot = (int) (me->query("potential")) - (int) (me->query("learned_points"));

        if(pot >= 1000 ) {
                tell_object(me, HIY"搞这么多潜能干嘛？快学了!\n"NOR);
                return 1;
        }

        if( me->query("combat_exp") < 10000 ) {
                message_vision(CYN"工头好心的劝$N说道:你太单薄了，做不了这活。听说城里醉仙楼在找零工，你去那里试试吧。\n"NOR,me); 
                return 1;
        }

        if( me->query("combat_exp") > 50000 ) {
        message_vision(CYN"工头对$N说道：哟！我可不敢劳您大驾。\n"NOR,me); 
        return 1;
        }

        message_vision(CYN"工头对$N说道：这可是重体力活，你去帮我砍点木料吧。\n"NOR,me); 
        me->set_temp("gongzuo/famu", 1);
        return 1;   
}

int accept_object(object me, object ob)
{
        object obj;
        
        if( !me || environment(me) != environment() ) 
                return 0;
        
        if ( !objectp(ob) ) 
                return notify_fail("你没有这样东西。\n");
        
        if ( !present(ob, me) )
                return notify_fail("你没有这样东西。\n");

        if (me->query_temp("gongzuo/famu") < 1) {
                message_vision(CYN"工头对$N说道：你想骗工钱啊！\n"NOR,me);
                return 0;
        }
                
        if ( (string)ob->query("name") != "木料" 
        && (string)ob->query("id") != "mu liao") {
                message_vision(CYN"工头对$N说道：你欠揍是不是！\n"NOR,me); 
                return 0;
        }

        if ( ob->query("possession") != me->query("id") ) {
                me->delete_temp("gongzuo/famu");
                message_vision(CYN"工头对$N说道：哼！工作要自己做，拿别人的成果算什么！\n"NOR,me);
                return 0;
        }

        if ( this_object()->query_temp("busy") ) {
                message_vision(CYN"工头对$N说道：别急！别急！一个一个来。\n"NOR,me);
                return 0;

        } else {
                message_vision(CYN"工头对$N说道：就这麽多了，拿去吧。\n"NOR,me);
                message_vision(CYN"工头递给$N一些碎银。\n"NOR,me);  
                me->delete_temp("gongzuo/famu");
                obj=new("/clone/money/silver");
                obj->set_amount(50+random(50));
                obj->move(me);
                this_object()->set_temp("busy",1);
                call_out("destroying", 1, this_object(), ob);
                return 1; 
        }
}

void destroying(object me, object obj)
{
        remove_call_out("do_destruct");
        
        if ( !obj || !( obj = present(obj, this_object()) ) )
                call_out("do_destruct",1,obj);
                        
        destruct(obj);
        this_object()->delete_temp("busy");
}
