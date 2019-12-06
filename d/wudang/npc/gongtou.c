#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
void create()
{
        set_name("��ͷ", ({"gong tou", "gongtou", "gong", "tou"}));
        set("gender", "����");
        set("age", 40);
        set("long", "����һ����ʮ�����ҵĹ�ͷ������һ�����⡣\n");
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
                "����" : (: do_gongzuo :),
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
                tell_object(me,"�������ֻ����ˣ���ȥ��\n");
                return 1;
        }  
        pot = (int) (me->query("potential")) - (int) (me->query("learned_points"));

        if(pot >= 1000 ) {
                tell_object(me, HIY"����ô��Ǳ�ܸ����ѧ��!\n"NOR);
                return 1;
        }

        if( me->query("combat_exp") < 10000 ) {
                message_vision(CYN"��ͷ���ĵ�Ȱ$N˵��:��̫�����ˣ�����������˵��������¥�����㹤����ȥ�������԰ɡ�\n"NOR,me); 
                return 1;
        }

        if( me->query("combat_exp") > 50000 ) {
        message_vision(CYN"��ͷ��$N˵����Ӵ���ҿɲ���������ݡ�\n"NOR,me); 
        return 1;
        }

        message_vision(CYN"��ͷ��$N˵������������������ȥ���ҿ���ľ�ϰɡ�\n"NOR,me); 
        me->set_temp("gongzuo/famu", 1);
        return 1;   
}

int accept_object(object me, object ob)
{
        object obj;
        
        if( !me || environment(me) != environment() ) 
                return 0;
        
        if ( !objectp(ob) ) 
                return notify_fail("��û������������\n");
        
        if ( !present(ob, me) )
                return notify_fail("��û������������\n");

        if (me->query_temp("gongzuo/famu") < 1) {
                message_vision(CYN"��ͷ��$N˵��������ƭ��Ǯ����\n"NOR,me);
                return 0;
        }
                
        if ( (string)ob->query("name") != "ľ��" 
        && (string)ob->query("id") != "mu liao") {
                message_vision(CYN"��ͷ��$N˵������Ƿ���ǲ��ǣ�\n"NOR,me); 
                return 0;
        }

        if ( ob->query("possession") != me->query("id") ) {
                me->delete_temp("gongzuo/famu");
                message_vision(CYN"��ͷ��$N˵�����ߣ�����Ҫ�Լ������ñ��˵ĳɹ���ʲô��\n"NOR,me);
                return 0;
        }

        if ( this_object()->query_temp("busy") ) {
                message_vision(CYN"��ͷ��$N˵�����𼱣��𼱣�һ��һ������\n"NOR,me);
                return 0;

        } else {
                message_vision(CYN"��ͷ��$N˵������������ˣ���ȥ�ɡ�\n"NOR,me);
                message_vision(CYN"��ͷ�ݸ�$NһЩ������\n"NOR,me);  
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
