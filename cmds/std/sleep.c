// sleep.c
// Dec.11 1997 by Venus
#include <ansi.h>;
#include <command.h>;
void wakeup(object me, object where);
int wakeup2(object me,object slept,object where);
int birth1(object me,object obj);
void birth2(object me, object where);
//void del_sleeped(object me);

int main(object me, string arg)
{
        object obj, old_target;
//        object *living_list;
//        int i, count;
        int i;
        object *inv;
        mapping fam;
        object where = environment(me);
        seteuid(getuid());

        if ( (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("���ﲻ������˯�ĵط���\n");

        if (me->is_busy())
                return notify_fail("����æ���أ�\n");
        if( me->is_fighting() )
                return notify_fail("ս���в���˯����\n");
        //modify by byp@MX
        //�͵괦��
        if (where->query("hotel") && !(me->query_temp("rent_paid"))) {
                message_vision("��С���������$N��У������ﵱ�����������ȸ�Ǯ������˯��\n",me);
                return 1;
        }
/*
        //����ڿ͵꣬���������˾Ͳ��� sleep
        if(where->query("hotel")) {
                living_list = all_inventory(where);
                for(i=0; i<sizeof(living_list); i++) {
                        if( !objectp(obj = present(living_list[i], where)) ) continue;
                        if( !obj->is_character() ) continue;
                        if( obj->is_corpse() > 0 ) continue;
                        count++; 
                }
                if(count>2) return notify_fail("����������̫�࣬����ôҲ˯���š�\n");
        }
*/

//        if ((time()-me->query("last_sleep"))<120)
//                return notify_fail("���˯��һ�����Ȼ��ɡ� \n");
/*
        if (me->query_temp("sleeped"))
            return notify_fail("�������������˯��һ������˯�������к����棡\n");
        if (me->query("marks/insleeping"))
        {
            me->set("marks/insleeping",0);
            me->set_temp("sleeped",1);
            call_out("del_sleeped", 179, me);
            return notify_fail(
"�������ϴ��˳�ǰû����˯�����������ӣ�ֻ�����ڿ�ʼ���㡣\n");
        }
*/

        if((!arg)||arg==(string)me->query("id"))
        {
            if (where->query("sleep_room"))
            {
                write("��������һ�ɣ���ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
                me->set_temp("block_msg/all",1);
                 me->set("last_sleep",time());
        me->set("no_get", 1);
        me->set("no_get_from", 1);
        me->set("no_beg", 1);
        me->set("no_beg_from", 1);
        me->set("no_steal", 1);
        me->set("no_steal_from", 1);
                message_vision(
"$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);
            }
            else {
                write("�������½���һ�ɣ���ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
                me->set_temp("block_msg/all",1);
                 me->set("last_sleep",time());
        me->set("no_get", 1);
       me->set("no_get_from", 1);
        me->set("no_beg", 1);
        me->set("no_beg_from", 1);
        me->set("no_steal", 1);
        me->set("no_steal_from", 1);
                message_vision(
"$N�����½�������һ�ɣ���һ�����������������������\n",me);
            }

            where->add_temp("sleeping_person", 1);

            if (where->query("hotel"))
                me->delete_temp("rent_paid");
                
            me->set_temp("sleeped",1);
            me->set_temp("in_sleeping",1);
            me->disable_player("<˯����>");

            call_out("wakeup",random(10)+1, me, where);

            return 1;
        }

        if(!objectp(obj = present(arg, where)))
            return notify_fail("�����˭һ��˯��\n");
        if( !obj->is_character() )
            return notify_fail("���Դ���ë���ˣ�\n");
        if( !userp(obj) )
            return notify_fail("�˼ҿɲ�Ը���㣡\n");
//can't sleep with npc...
        if(me->query("gender")==obj->query("gender"))
            return notify_fail("���Է��������ͬ���أ�����\n");
        if( !living(obj) )
            return notify_fail(obj->name() + "û������˯�ˡ�\n");
        if (!where->query("if_bed"))
            return notify_fail("���������̫�ðɡ�\n");
        if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 50 )
            return notify_fail("��������������������㡣\n");

        if( userp(obj) && (object)obj->query_temp("pending/sleep")!=me )
        {
            message_vision(RED "\n$N���������ض�$n˵���ң�����\n\n" NOR, me, obj);
            if( objectp(old_target = me->query_temp("pending/sleep")) &&
                !((string)old_target->query("id")==(string)obj->query("id")))
                tell_object(old_target, YEL + me->name() + "�ı����ⲻ�����˯�ˡ�\n" NOR);
            me->set_temp("pending/sleep", obj);
            tell_object(obj, YEL "����" + me->name() +
                "("+(string)me->query("id")+")"+
                "������㣮���������Ը�⣬��Ҳ��һ�� sleep ָ�\n" NOR);
            write(YEL "�Է����ڿ����У�����\n" NOR);
            return 1;
        }
        message_vision(RED "\n$N����$n���ĵ�һЦ�����˵�ͷ��\n\n" NOR, me, obj);

        inv = all_inventory(me);
            for(i=0; i<sizeof(inv); i++)
                REMOVE_CMD->do_remove(me, inv[i]);
        inv = all_inventory(obj);
            for(i=0; i<sizeof(inv); i++)
                REMOVE_CMD->do_remove(obj, inv[i]);

        if(me->query("gender")=="����")
        {
            tell_object(me, HIY "\n\n��§��"+obj->query("name")+
                "��������壬���ɵ��������ԣ�����\n\n\n" NOR);
            tell_object(obj, HIY "\n\n������"+me->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        else
        {
            tell_object(obj, HIY "\n\n��§��"+me->query("name")+
                "��������壬���ɵ��������ԣ�����\n\n\n" NOR);
            tell_object(me, HIY "\n\n������"+obj->query("name")+
                "�Ļ�����ɵ��������ԣ�����\n\n\n" NOR);
        }
        me->set("last_sleep",time());
        obj->set("last_sleep",time());
        me->set_temp("block_msg/all",1);
        obj->set_temp("block_msg/all",1);
        message_vision(HIY "$N��$n���뱻�У�§��һ��˯���ˣ�����\n\n\n" NOR,me,obj);
        me->disable_player("<˯����>");
        obj->disable_player("<˯����>");

        call_out("wakeup2",random(15 - me->query("con")) + 0, me,obj, where);
        call_out("wakeup2",random(15 - obj->query("con")) + 0, obj, me,where);
 
        return 1;
}
void wakeup(object me,object where)
{
        object env;
        if(!me) return;
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("jingli", me->query("max_jingli")/2 - me->query("jingli")/2 );
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
        me->enable_player();
        //�͵괦��
        if (where->query("temp_hotel"))
                me->delete_temp("rent_paid");
                
        me->delete("no_get");
        me->delete("no_get_from");
        me->delete("no_beg");
        me->delete("no_beg_from");
        me->delete("no_steal");
        me->delete("no_steal_from");
        me->delete_temp("sleeped");  //for sleepbag
        me->set_temp("in_sleeping",0);
        while( environment(me)->is_character() || environment(me)->is_container() )
                me->move(environment(environment(me)));
        env = environment(me);
        me->move(VOID_OB,1);
        me->move(env,1);
        message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
        me->set_temp("block_msg/all", 0);
        write("��һ��������ֻ���������档�ûһ���ˡ�\n");
        where->add_temp("sleeping_person", -1);
}


int wakeup2(object me,object slept,object where)
{
        int qi_cost;
        object obj, env;

        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
        me->enable_player();
        me->set_temp("in_sleeping",0);
        qi_cost=50+5*((int)me->query("str")-(int)me->query("con"));
        if(qi_cost>(int)me->query("max_qi")/2)
            qi_cost=(int)me->query("max_qi")/2+1;
        me->add("qi", -qi_cost);
        if (me->query("qi") <= 0) me->set("qi", 10);

        while( environment(me)->is_character() || environment(me)->is_container() )
        me->move(environment(environment(me)));
        env = environment(me);
        me->move(VOID_OB,1);
        me->move(env,1);

        if(me->query("gender")=="����")
        {
            message_vision(HIY "$N���˹������ƺ����������Ҹ�֮�С�\n" NOR,me);
            me->set_temp("block_msg/all", 0);
            write("�����˹������ƺ����������Ҹ�֮�С�\n");
            return 1;
        }
        else
        {
// add bearing function here.
            message_vision(HIY "$N���˹��������ϻ��������۵�Ц�ݡ�\n" NOR,me);
            me->set_temp("block_msg/all", 0);
            write("�����˹��������ϻ��������۵�Ц�ݡ�\n");
            obj=slept;
            //if((int)(me->query("mud_age")/86400) < 6 || (int)(me->query("mud_age")/864000) < me->query("child"))
            if((int)(me->query("mud_age")/86400) < 1 || (int)(me->query("mud_age")/864000) < me->query("child"))
                return 1;
            if (obj!=slept )
            {
                if (!obj || !userp(obj) || !find_player(obj->query("id")))
                {
                    message_vision(HIY "\n$N�ƺ����ø���һ���ʹ������ҧҧ����������վ��������\n"NOR, me);
                    write("\n�ɷ򶼲��ڣ���ôҲ���ܰѺ���������������\n");
                } else {
                    message_vision(HIY "\n$N�ƺ����ø���һ���ʹ�������ߺ�������ҧҧ��վ��������\n"NOR, me);
                    write("\n��ô������ײ���ˣ�������\n");
                }
                me->set("neili", me->query("neili")/2);
                me->set("qi", me->query("qi")/2);
                me->set("jing", me->query("jing")/2);
                return 2;
            } else {
                if((int)(me->query("mud_age")/86400) < 1 || (int)(me->query("mud_age")/864000) < me->query("child"))
                {
                    message_vision(HIY "\n$N��������һ�����������������ƽ��������\n"NOR,me);
                    return 1;
                }
                me->set_temp("is_bearing",1);
                me->start(100);
                obj->start(100);
                message_vision(HIY "\n$N��������һ��������Ͻ���ס$n���֣�����˵����Ҫ����! \n" NOR, me,obj);
                call_out("birth1",15,me,obj);
                return 3;
            }
        }
}

int birth1(object me,object obj)
{
    message_vision(HIY "\n$N���Ǵ����죬һֱ���ں������أ�˫�ֽ�����ס$n���ֲ��š�\n"+
        "\nӤ���Ѿ�̽����ͷ������\n"NOR,me,obj);
    call_out("birth2",15,me,obj);
    return 1;
}

void birth2(object me,object obj)
{
    object baby;
    int number;
    message_vision(HIY "\n���ۡ���������Ӥ�������ˣ�\n"+
        "\n$N��ɫ�԰ף�б���ڴ�ͷ���������������¶��һ˿΢Ц��\n"NOR, me);
    me->start_busy(1);
    obj->start_busy(1);
    me->set("neili",0);
    me->set("qi",0);
    me->set("jing",0);
    baby=new("/d/taohuacun/npc/baby");
    baby->set("long", baby->query("long")+"����"+obj->query("name")+"��"+me->query("name")+"�ĺ��ӡ�\n");
    if (random(100)<50)
    {
        baby->set("gender","����");
        baby->set_name("С"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
    }
    else
    {
        baby->set("gender","Ů��");
        baby->set_name("С"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
    }
    me->add("child",1);
    obj->add("child",1);
    baby->set("parents",({me->query("id"),obj->query("id")}));
    number=me->query("child");
    me->set("child_"+number+"/gender",baby->query("gender"));
    me->set("child_"+number+"/long",baby->query("long"));
    me->set("child_"+number+"/name",baby->query("name"));
    me->set("child_"+number+"/id",({baby->query("id"),"baby"}));
    me->set("child_"+number+"/parents",baby->query("parents"));
    number=obj->query("child");
    obj->set("child_"+number+"/gender",baby->query("gender"));
    obj->set("child_"+number+"/long",baby->query("long"));
    obj->set("child_"+number+"/name",baby->query("name"));
    obj->set("child_"+number+"/id",({baby->query("id"),"baby"}));
    obj->set("child_"+number+"/parents",baby->query("parents"));
    me->delete_temp("is_bearing");
    me->save();
    obj->save();
   //this needs to be put at the last since
   //can only move the baby after it's parameters are set.
    if(!baby->move(environment(me)))
        baby->move(environment(environment(me)));
}
/*
void del_sleeped(object me)
{
        if (objectp(me) &&  me->query_temp("sleeped"))
                me->delete_temp("sleeped");
}
*/
int help(object me)
{
  write(@HELP
ָ���ʽ : sleep <����>
 
����˼�壬���ָ��������˯���ġ�
HELP
    );
    return 1;
}


