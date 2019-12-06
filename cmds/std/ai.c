// ai.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
//    mapping fam;
    object obj, old_target, where = environment(me);

    if (me->query("age") < 17)
         return notify_fail("����ʮ���궼û������ѧ������\n");

    if (me->query("mud_age")-me->query("marks/makelove") < 180)
         return notify_fail("һ����������������Ԫ���ģ������Ϣһ��ɡ�\n");

    if ( !(where->query("sleep_room"))|| (where->query("no_sleep_room")) )
         return notify_fail("�������µ�Ȼ��Ҫһ����ȫ�ĵط���\n");

    if (!arg || !objectp(obj = present(arg, environment(me))))
         return notify_fail("�����ںܳ嶯������һ���޶�û�С�\n");

    if (me->query("gender") =="����")
         return notify_fail("�����Ǹ����߶�û�У�����ɺ��£�\n");

    if(obj==me) return notify_fail("���Լ�������Ǿ�û��Ҫ��ô�鷳�\n");
    if(query_ip_name(obj)==query_ip_name(me))
         return notify_fail("���Լ�������Ǿ�û��Ҫ��ô�鷳�\n");

    if (obj->query("age") < 17)
         return notify_fail("�˼�ʮ���궼û�������뺦�˰���\n");

    if (userp(obj) && obj->query("mud_age")-obj->query("marks/makelove") < 180)
         return notify_fail("һ����������������Ԫ���ģ���"+obj->query("name")+"��Ϣһ��ɡ�\n");

    if (obj->query("gender") == me->query("gender"))
         return notify_fail("�����д󺰣���ϧ���Է�����ṹ��Ȼ����һ����\n");

    if (!obj->is_character()) return notify_fail("�ۣ����Ķ��������Ź�����\n");

    if (!living(obj) )
         return notify_fail(obj->name() + "��������û�������ɴ�ǿ����ˡ�\n");

    if (userp(obj) && (object)obj->query_temp("pending/ai")!=me )
    {
         message_vision("\n$N����$n˵�����ҵİ��ˣ���...�����������.\n\n",me,obj);
         if( objectp(old_target = me->query_temp("pending/ai")) )
             tell_object(old_target,YEL+me->name()
                    + "��Ȼ����ûʲô��Ȥ�ˡ�\n"NOR);
         me->set_temp("pending/ai", obj);
         tell_object(obj, YEL"�������ܶԷ�����������Ҳ��" + me->name() 
             + "("+(string)me->query("id")+")"+ "��һ�� ai ָ�\n" NOR);

         write(YEL "�Է�����ҿ��Ƶ���������ȶԷ�ͬ����ܸ����¡�\n" NOR);
         return 1;
    }

    if (!userp(obj) && ( random(10)!=2)) 
    {
         message_vision("\n$n��$NŭĿ����: ��������������˦ͷ�����ˡ�\n",me,obj);
         destruct(obj);
         return 1;
    } else
    {
         message_vision("\n$N��$n����һ�����������ᣬ����������\n",me,obj);
         obj->start_busy(3);
         me->start_busy(3);
         message_vision("�����ã�$N��$n�������棬�������\n\n", me,obj);

         me->add("eff_jing",-5);
         me->add("jing",-10);
         me->set("qi",me->query("eff_qi"));
         if (obj->query("id") == me->query("couple/couple_id"))
            me->set("neili",me->query("max_neili"));
         else
            me->add("neili",10);
         me->add("combat_exp",1);
         me->delete_temp("pending/ai");
         me->save();
         me->set("marks/makelove",me->query("mud_age"));
         obj->add("eff_jing",-5);
         obj->add("jing",-10);
         obj->set("qi",obj->query("eff_qi"));
         obj->delete_temp("pending/ai");
         if (userp(obj))
         {
             if (me->query("id") == obj->query("couple/couple_id"))
                 obj->set("neili",obj->query("max_neili"));
             else
                 obj->add("neili",10);
             obj->save();
             obj->set("marks/makelove",obj->query("mud_age"));
         }
     }
     me->set("couple/have_couple",1);
     obj->set("couple/have_couple",1);
     return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : ai <����>

���ָ��������һ��������а����������ľ�����ȴ���Բ������������
�������飬���������״�����Ҫ��ᱻ�ܾ���

�������ָ��: qiangjian

HELP
    );
    return 1;
}

