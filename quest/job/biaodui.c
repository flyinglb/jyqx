#include <ansi.h>

inherit ITEM;

int j, i;

void make_bs(object me, object ob, int j);  

void create()
{
        set_name("�����ڶ�", ({ "fuwei"}));
        set("unit", "ֻ");
        set_weight(90000000);
        set("long", "
һֻԶ���������ڶӣ���������˻���м��
��һ�����죬�ƺ�д�š������ھ֡��ĸ����֡�����\n");
        set("no_get", 1);
        set("no_drop", 1);
        set("no_put",1);

        j = query_temp("j");
        if (j=4)
                set("i", 4);
        else if (j=5)
                set("i", 5);
        else if (j>6)
                set("i", 6);
        else
                set("i", 3);

}

void init()
{
        remove_call_out("aaa");
        call_out("aaa", 60, this_object());  
        add_action("do_rob", "qiang");
}

int do_rob()
{
        object me, ob;
        string arg;
        int stage;
        me = this_player();
        ob = this_object();
        stage = 0;
        arg = query("arg");

        ob -> set("rob_id",query("id"));
        
        if(!living(me))
                return 0;
        
        if(!me->query_temp("rob_start")) 
                return notify_fail("�㵨�Ӳ�С�������ڸ����ھ�ͷ�ϴ�ע�⣿\n");
        
        if(objectp(present("biaoshi", environment(me))))
                return notify_fail("������ʦ�����书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  

        message_vision(HIY"$N����$n���һ����߾��\n��ɽ���ҿ������������أ�\nҪ���·����������·�ƣ�����\n"NOR, me, ob);
        me->set_temp("xx_rob", 1);
        make_bs(me, ob, j); 
        return 1;     
}

void make_bs(object me, object ob, int j)
{
        object obj, obj1;

        
        j = me->query_temp("j");
        i = ob->query("i");


                obj1 = new(__DIR__"tangzishou");
                obj1 -> move(environment(me));
                message_vision(HIR"ͻȻ�ӳ��Ӻ�ܳ�һ��$N��������˵��������$n��\n"NOR, obj1, me);
//                obj1 -> go_back(me);
                obj1 -> kill_ob(me);
                me -> kill_ob(obj1);

        if (j>0){
                if (random(i))
                        obj=new(__DIR__"tangzishou");
                else {
                        obj=new(__DIR__"biaoshi");
                        obj->copy_player(me);
//                        obj->do_copy(me);
                }
                obj -> move(environment(me));
                message_vision(HIR"ͻȻ�ӳ��Ӻ�ܳ�һ��$N��������˵��������$n��\n"NOR, obj, me);
                obj -> kill_ob(me);
                me -> kill_ob(obj);
                ob -> query("last_opponent", ob ->query_temp("last_opponent") );
//                obj -> go_back(me);

                j = j-1;
                me -> set_temp("j",j);
        }
        else {
                message_vision(HIW"$N���Ѿ����˱��������ڳ��������Ĳ���ȫ�����ڻ��\n���ְ��ڳ��ƻ��������պ��˲����\n"NOR, me);    
                obj=new(__DIR__"red");
                obj->move(me);
                obj->set("owner", me->query("id"));
                me->add("shen", -100);
                me->delete_temp("rob_start");
                me->delete_temp("xx_rob");
                me->delete_temp("rob_job");
                me->delete_temp("j"); 
                me->delete("i");
                destruct(ob);
                remove_call_out("aaa");
                return;                 
        }
}

void aaa(object me)
{
        message_vision("$Nת������Сɽ��Ͳ����ˡ�\n",me);
        me->delete_temp("rob_start");
        me->delete_temp("xx_rob");
        me->delete_temp("rob_job");
        me->delete_temp("j");
        destruct(me);
        return;
}


