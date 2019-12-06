// sleepbag.c
inherit ITEM;

protected void wakeup(object me,object where);
protected void del_sleeped(object me);

#include <ansi.h>
#include <command.h>
void create()
{
        set_name("˯��",({"sleepbag"}));
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

int is_container()
{
     return 1;
}

void init()
{
    if (environment()==this_player())
                add_action("do_sleep","sleep",1);
}

int do_sleep(string arg)
{
//      int i;
    object me;
    object where;
    me = this_player();
    where = environment(me);
        seteuid(getuid());
    if (arg) return 0;
        if( where->query("sleep_room") || where->query("freeze"))
             return 0;
    if( where->query("no_sleep_room"))  return 0;
        if ( me->query("family/family_name") == "ؤ��") return 0;
        if (me->is_busy()) { write("����һ������δ��ɣ�\n"); return 1;}
        if( me->is_fighting() ) { write("ս����˯��������ѽ��\n"); return 1;}
        if (me->query_temp("sleeped"))
        {
            write("���˯��һ��, ����ȥ����! \n"); 
            return 1;
         }
             message_vision("$Nչ��һ��˯�������˽�ȥ����һ��ͽ��������磡\n",me);

        where->add_temp("sleeping_person", 1);
        me->set("no_get", 1);
        me->set("no_get_from", 1);
        me->set_temp("block_msg/all",1);
        me->set_temp("sleeped",1);
        me->disable_player("<˯����>");
              call_out("wakeup", 30, me, where);
   return 1;
}

protected void wakeup(object me,object where)
{
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->enable_player();
    me->move(environment(me));
        me->set_temp("block_msg/all", 0);
    if ( userp(me) && (!me->query("food") || !me->query("water")) ){
                message("vision",me->name()+"һ�����������ӡ�������һ�������˴��һ������\n",environment(me),({me}));
                write("��������һ������������о��ѣ�����ԭ�����Լ��Ķ����ڴ�ģ�\n");
        }else
        {
                message("vision",me->name()+"һ����������������ػ��һ�½�ǡ�\n",environment(me),({me}));
                write("��һ��������ֻ���������档�ûһ���ˡ�\n");
                me->set("qi",    me->query("eff_qi"));
                me->set("jing",  me->query("eff_jing"));
        }  
          call_out("del_sleeped", 90, me);
    if (where)
                where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");      
}

protected void del_sleeped(object me)
{
        if (objectp(me))
                me->delete_temp("sleeped");
}

