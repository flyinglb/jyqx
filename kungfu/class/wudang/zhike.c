// zhike.c ֪��

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("֪�͵���", ({ "zhike daozhang", "lingxu daozhang", "lingxu", "zhike" }));
        set("long",
                "���������飬���䵱ɽ��֪�͵�����\n");
        set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("no_get", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);

        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 5000);
        set("score", 1000);

        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        set_skill("wudang-jian", 20);
        set_skill("taoism", 20);

        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("�䵱��", 3 , "����");
        set("chat_chance",2);
        set("chat_msg", ({
            "֪�͵���˵�������䵱�����˽ܣ����ʢ�������µ��˶������ݾ��㡣\n",
            "֪�͵���˵�������������䵱�����Ż����ҵ�һ��Ҫ��������(volunteer)������˿��и����\n"
        }));
        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        object ob;

        ::init();
        if(base_name(environment()) != "/d/wudang/xuanyuegate") {
                object *me;
                int i;
//                tell_room(environment(),"����ˣ�����ô�������ˣ�\n֪�͵���˵�ž����˳�ȥ��\n"
//                ,this_object())
                me = users();
                for (i = 0; i < sizeof(me); i ++) {
                        if(!me[i]->query_temp("in_guard")) continue;
                        me[i]->delete_temp("in_guard");
                        if(stringp(me[i]->query("title_temp"))) {
                                me[i]->set("title", me[i]->query("title_temp"));
                                me[i]->delete("title_temp");
                        }
                }
                destruct(this_object());
                return;
        }
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_volunteer","volunteer");
        add_action("do_unvolunteer","unvolunteer");
}

void greeting(object ob)
{
        if(ob->query("family/family_name")!="�䵱��")
              say ("֪�͵���Ц�����˵����λ"+RANK_D->query_respect(ob) + "����ӭ���䵱���������ȱ��裬ЪЪ�Ȱɡ�\n");
        else
              say ("֪�͵���Ц�����˵����λ"+RANK_D->query_respect(ob) + "��һ·�����ˡ�\n");
        return;
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 1) {
                command("say " + RANK_D->query_respect(ob) +
                        "������䵱�ɾ��˶����������м��������أ�");
                return;
        }
        if ((int)ob->query("guarded") < 5) {
                command("say " + RANK_D->query_respect(ob) +
                        "�������䵱���£��㻹��Ҫ���Ŭ�����ĲŶԡ�");
                return;
        }
        if ((int)ob->query("shen") < 0) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        command("recruit " + ob->query("id"));
}

int do_volunteer()
{
        object me = this_player();
        string str;

        if (me->query_temp("in_guard")) 
           return notify_fail("֪�͵�������˵����ר���غ�ɽ�ţ���������ݹ���\n");

/*
        if( me->query("combat_exp") > 500000 )
                return notify_fail("֪�͵�������˵����λ"+ RANK_D->query_respect(me)+"�ο��ƶ���������Ц��\n");
*/
        if( (time() - me->query_temp("last_guard")) < 600 )
                return notify_fail("֪�͵�������˵������ع�ɽ�ţ���ȥ��Ϣһ��ɡ�\n");
        
        if ((query_temp("in_guard1") > 0)  && (query_temp("in_guard2") > 0)  )
                return notify_fail("֪�͵�������˵����ɽ�ŵ����Ѿ����ˣ���һ�������ɡ�\n");
        
        tell_room(environment(me),me->query("name")+"��ʼ���䵱ɽ��ֵ�ء�\n");
        me->set("title_temp", me->query("title"));
        me->set("title", HIG"�䵱ɽ������"NOR);
        me->set_temp("in_guard", 1);
        me->set_temp("last_guard",time());

        if(query_temp("in_guard1") > 0) str = "2";
        else str = "1";

        if(me->query("family/family_name")!="�䵱��") {
                me->set_temp("in_guard"+ str, 1);
                this_object()->set_temp("in_guard"+str, 1);
                call_out("checking"+str, 3, me);
                call_out("end_guard"+str, 150, me);
                call_out("clone_meng"+str, random(10)+30, me);
        } else {
                me->set_temp("in_guard"+str, 1);
                this_object()->set_temp("in_guard"+str, 1);
                call_out("checking"+str, 3, me);
                call_out("end_guard"+str, 300, me);
                call_out("clone_meng"+str, random(10)+20, me);
        }
        me->save();
        return 1;
}

int do_unvolunteer()
{
        object me = this_player();
        
        if(me->query_temp("in_guard")!= 1) 
                return notify_fail("�����ڲ�û����ְ�ء�\n");

        me->delete_temp("in_guard"); 
        
        if(me->query_temp("in_guard1") > 0) {
                this_object()->delete_temp("in_guard1"); 
                remove_call_out("clone_meng1");
                remove_call_out("end_guard1");
                remove_call_out("checking1");
        } else {
                this_object()->delete_temp("in_guard2"); 
                remove_call_out("clone_meng2");
                remove_call_out("end_guard2");
                remove_call_out("checking2");
        } 
        if(stringp(me->query("title_temp"))) {
                me->set("title", me->query("title_temp"));
                me->delete("title_temp");
        }
        tell_room(environment(me),me->query("name")+"�����䵱ɽ��ֵ�صĹ�����\n");
        tell_object(me,"������䵱ɽ��ֵ�صĹ�����\n");
        return 1;
}

void clone_meng1(object me)
{
        object ob;
        tell_room(environment(me),"ɽ��ͻȻ������һ������󺺡�\n");
        ob=new("/d/wudang/npc/mengmian.c");
        ob->move("/d/wudang/xuanyuegate");
        call_out("clone_meng1", random(50)+80, me);
}

void clone_meng2(object me)
{
        object ob;
        tell_room(environment(me),"ɽ��ͻȻ������һ������󺺡�\n");
        ob=new("/d/wudang/npc/mengmian.c");
        ob->move("/d/wudang/xuanyuegate");
        call_out("clone_meng2", random(50)+80, me);
}

void end_guard1(object me)
{
        if(!me->query_temp("in_guard")) return;

        me->delete_temp("in_guard"); 
        remove_call_out("checking1");
        remove_call_out("clone_meng1");

        if(me->query("family/family_name") != "�䵱��") {
                me->add("combat_exp",10);
                me->add("potential",5);
        } else {
                if( me->query("combat_exp")< 500000 ){
                me->add("combat_exp", random(100)+4000);
                me->add("potential", random(50)+100);
                }
        }                
                
        me->add("guarded",1);
        if(stringp(me->query("title_temp"))) {
                me->set("title", me->query("title_temp"));
                me->delete("title_temp");
        }
        this_object()->delete_temp("in_guard1"); 

        if ((int)me->query("potential")-(int)me->query("learned_points")>100)
                me->set("potential",(int)me->query("learned_points")+100);

        me->save();
        tell_room(environment(me),me->query("name")+"���䵱ɽ��ֵ����������\n");
        tell_object(me,"�����䵱ɽ��ֵ����������\n");
}

void end_guard2(object me)
{
        if(!me->query_temp("in_guard")) return;

        me->delete_temp("in_guard"); 
        remove_call_out("checking2");
        remove_call_out("clone_meng2");

        if(me->query("family/family_name") != "�䵱��") {
                me->add("combat_exp",10);
                me->add("potential",5);
        } else {
                if( me->query("combat_exp")< 500000 ){
                me->add("combat_exp", random(100)+4000);
                me->add("potential", random(50)+100);
                }
        }                
                
        me->add("guarded",1);
        if(stringp(me->query("title_temp"))) {
                me->set("title", me->query("title_temp"));
                me->delete("title_temp");
        }
        this_object()->delete_temp("in_guard2"); 

        if ((int)me->query("potential")-(int)me->query("learned_points")>100)
                me->set("potential",(int)me->query("learned_points")+100);

        me->save();
        tell_room(environment(me),me->query("name")+"���䵱ɽ��ֵ����������\n");
        tell_object(me,"�����䵱ɽ��ֵ����������\n");
}

//�������
void checking1(object who)
{
    if(!who->query_temp("in_guard")) return;
        if ( who->is_ghost() ) {
            who->delete_temp("in_guard"); 
            remove_call_out("checking1");
            remove_call_out("end_guard1");
            remove_call_out("clone_meng1");
            if(stringp(who->query("title_temp"))) {
                who->set("title", who->query("title_temp"));
                who->delete("title_temp");
            }
            this_object()->delete_temp("in_guard1"); 
            return;
        }
        remove_call_out("checking1");
        call_out("checking1", 5, who);
    return;
}

void checking2(object who)
{
    if(!who->query_temp("in_guard")) return;
    if ( who->is_ghost() ) {
            who->delete_temp("in_guard"); 
            remove_call_out("checking2");
            remove_call_out("end_guard2");
            remove_call_out("clone_meng2");
            if(stringp(who->query("title_temp"))) {
                who->set("title", who->query("title_temp"));
                who->delete("title_temp");
            }
            this_object()->delete_temp("in_guard2"); 
                        return;
        }
        remove_call_out("checking2");
        call_out("checking2", 5, who);
    return;
}

void die()
{
        object *me;
        int i;

        me = users();
        for (i = 0; i < sizeof(me); i ++) {
                if(!me[i]->query_temp("in_guard")) continue;
                me[i]->delete_temp("in_guard");
                if(stringp(me[i]->query("title_temp"))) {
                        me[i]->set("title", me[i]->query("title_temp"));
                        me[i]->delete("title_temp");
                }
        } 
        this_object()->delete_temp("in_guard1");
        this_object()->delete_temp("in_guard2");
        ::die();
}
