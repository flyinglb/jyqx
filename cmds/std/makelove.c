// makelove.c
// modified by wind

#include <ansi.h>

void over(object,object);

int main(object me, string arg)
{
//        object obj, old_target;
        object obj;
//        object *ob,*inv;
        object *ob;

//        int i,j;
        int i;

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail("�����˭������\n");


        if( !obj->is_character()||me->query("gender")==obj->query("gender") )
                return notify_fail("����...?!���²��а�?\n");

        if(!living(obj))
                return notify_fail("�˼Ҷ������ˣ��㻹...\n");
/*
        if(!me->query("couple/have_couple") ||me->query("couple/couple_id")!=arg
)
                 return notify_fail("�Է�������İ���,��������Υ���ġ�\n");
*/

        if( !environment(me)->query("sleep_room")||
                 environment(me)->query("no_sleep_room"))
                return notify_fail("�ܵ��Ҹ���ܰ����ĵط��ɡ�\n");

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)
                if( ob[i]->is_character()&&ob[i]!=me
                        &&ob[i]!=obj&&!wizardp(ob[i]) )
                        return notify_fail("������б����أ��಻����˼ѽ��\n");
        if(!me->query_temp("makelove/quest"))
        {

            if((me->query("gender")=="����"))
                {
                   message_vision(HIM "$N��������$n���˫�ֻ�����$n������,
��$n��������˵�����װ��ģ�����...\n"NOR,me,obj);
                tell_object(obj, HIR "ɵ��Ҳ�ܿ�����������㹲������,
�����Ը�⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� ma
kelove ָ�\n" NOR);
                }
            else
                {
                        message_vision(HIM "��֪����Ϊ��⣬���Ǿƾ����������Ϊ�˷ܣ�$N��С�������ģ�
���žƱ�,$Nֱ�����ض���$n:�װ���...��˵...�Ⱦ�...����...\n"NOR,me,obj);
                tell_object(obj, HIR "ɵ��Ҳ�ܿ�����������㹲��������
�����Ը�⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� ma
kelove ָ�\n" NOR);
                }
                obj->set_temp("makelove/quest",1);

        }
        else
        {
            if((me->query("gender")=="����"))
                {
                        message_vision(HIM "$N�ؾ��ƵĶ���$n���۾�������һ�Բ�����ͻȻһ�ѱ�ס$n,һ˫�ȴ���ס��$n���죬
��$n��ֱ�������������Ʊ����������һ��...\n"NOR,me,obj);
                call_out("over", 1, me,obj);
                }
                else
                {
                        message_vision(HIM "$n�����ܿ���$N�ߺ�Ķ�����$N��������$n�Ļ�����
ĬĬ�ط�����ԡ��$nȴ��Ҳ�̲�ס��һ�ѽ�$N��������...\n"NOR,me,obj);
                call_out("over", 1, obj,me);
                }
                me->delete_temp("makelove/quest");
        }


        return 1;
}


void over(object me,object obj)
{
        message_vision(HIR"...һ�󼲷�����\n"NOR,me);
        if(me->query("qi")<30||me->query("jing")<30||obj->query("qi")<30||obj->query("jing")<30)
        {
                if(me->query("qi")<30||me->query("jing")<30)
                {
                    message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء�����������������."NOR,me);
                    me->unconcious();
                }
                else
                {
                    message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء�����������������."NOR,obj);
                    obj->unconcious();
                }
        }
        else
        switch(random(10))
        {
        case 0:
                message_vision(HIR "$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�����
��ȥ��\n"NOR,me);
                me->unconcious();
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                break;
        case 1:
                message_vision(HIR "$NͻȻ���һ������Ȼ�Ǽ����˷ܣ������ž�����
��ȥ��\n"NOR,obj);
                obj->unconcious();
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
                break;
        default:
                if(random(1))
                {
                        message_vision(YEL "$N����һ����ͷ�������һ������΢΢������$n,
��˵����Ҫ��Ȼ...��������һ��...\n"NOR,me,obj);
                }
                else
                {
                        message_vision(HIY "$n����������$N�Ļ����������������ţ�
�����Ǿ��ȵĺ������е����޵��Ҹ�...\n"NOR,me,obj);
                }
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
        }


}

int help(object me)
{
  write(@HELP
ָ���ʽ : makelove <����>
������
���֪ʶ�ο����С������������α�

HELP
    );
    return 1;
}

