// sleepbag.c
// Modified by Eatdami@MX (10/07/2000)

inherit ITEM;

protected void wakeup(object me,object where);
protected void del_sleeped(object me);
int do_sleep(string arg);

int is_container() { return 1; }
void create()
{
        set_name(YEL"˯��"NOR,({"sleepbag"}));
        set_weight(5000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long", "һ��˯������֪���Ǹ�ʲô�õġ�\n");
            set("unit","��");
            set("value", 1000);
        }
}

void init()
{
    if (environment()==this_player())
                add_action("do_sleep","sleep");
}
int do_sleep(string arg)
{
        int i;
        object me = this_player();
        object where = environment(me);

        if(arg) return 0;
        if( where->query("sleep_room") || where->query("freeze"))
                 return 0;
        if( where->query("no_sleep_room") )
                return 0;
        if( me->query("family/family_name") == "ؤ��")
                return 0;
        if( me->is_busy() ) {
                write("����һ������δ��ɣ�\n");
                return 1;
        }
        if( me->is_fighting() ) {
                write("ս����˯��������ѽ��\n");
                return 1;
        }
        if (me->query_temp("sleeped")) {
                write("���˯��һ��, ����ȥ����! \n");
                return 1;
        }
        message_vision("$Nչ��һ��˯�������˽�ȥ����һ��ͽ��������磡\n",me);
        i = random(100/me->query_con()+2);
        where->add_temp("sleeping_person", 1);
        me->set("no_get", 1);
        me->set("no_get_from", 1);
        me->set_temp("block_msg/all",1);
        me->set_temp("sleeped",1);
        me->set_temp("in_sleeping",1);
        me->disable_player("<˯����>");
        me->set("last_sleep",time());
        if ( i < 1 )
                i = 0;
        call_out("wakeup", 5, me, where);
        return 1;
}


protected void wakeup(object me,object where)
{
        object env,env2;

        if( !objectp(me) )
                return;

        while( (env = environment(me)) && env->is_character() && (env2 = environment(env)))
                me->move(env2,1);

        me->set_temp("in_sleeping",0);
        me->set_temp("block_msg/all",0);
        me->enable_player();
        me->move(environment(me),1);
        env = environment(me);
        me->move(VOID_OB,1);
        me->move(env,1);

        if ( userp(me) && (!me->query("food") || !me->query("water")) ){
                message("vision",me->name()+"һ�����������ӡ�������һ�������˴��һ������\n",environment(me),({me}));
                write("��������һ������������о��ѣ�����ԭ�����Լ��Ķ����ڴ�ģ�\n");
        }else{
                message("vision",me->name()+"һ����������������ػ��һ�½�ǡ�\n",environment(me),({me}));
                write("��һ��������ֻ���������档�ûһ���ˡ�\n");
                me->set("qi",    me->query("eff_qi"));
                me->set("jing",  me->query("eff_jing"));
//                me->add("neili", me->query("max_neili")/3 - me->query("neili")/3 );
                me->add("jingli", me->query("max_jingli")/3 - me->query("jingli")/3 );
        }  
        call_out("del_sleeped", 5, me);
        if( where ) where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");
}

protected void del_sleeped(object me)
{
        if( !objectp(me) ) return;
        me->delete_temp("sleeped");
        me->set_temp("in_sleeping",0);
}
