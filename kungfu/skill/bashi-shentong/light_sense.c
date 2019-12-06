// light_sense.c ��ʶ��ͨ
// Modified by Venus Oct.1997
// astral_vision.c

#include <ansi.h>

inherit F_SSERVER;

int conjure(object me, object target)
{
    object *ob;
    int i, skill, damage;
    if(me->query("jing")<10)
   return notify_fail("��ľ����㣡\n");
    if( (int)me->query("jingli") < 50 )
   return notify_fail("��ľ���������\n");
    skill = me->query_skill("magic");
    damage=0;
    me->add("jingli", - 50);
    me->receive_damage("jing", 10);
    if( random(me->query("jingli"))<150)
   {tell_room(environment(me),me->query("name")+"ߴߴ�������˼��䣬
��ʲôҲû��������\n",me);
    tell_object(me,"��ʧ���ˡ�\n");
   return 1;
   }
    message_vision(HIB "$N�������У�ʩչ������ʶ��֮������"NOR+
    "��\n", me);
    tell_room(environment(me),me->query("name")+"ȫ��������۵Ĺ�â������\n"
);
    ob = all_inventory(environment(me));
    if(sizeof(ob)==0) return 1;
    for(i=0; i<sizeof(ob); i++)
   {
    if( !living(ob[i]) || ob[i]==me||!(ob[i]->is_ghost())) continue;
    damage = (int)(skill+(ob[i]->query("qi"))*(me->query("max_jingli"))/3);
   if( damage > 0 ) {
      ob[i]->receive_damage("jing", damage);
      ob[i]->receive_damage("qi", damage);
      ob[i]->receive_wound("jing", damage/2);
      ob[i]->receive_wound("qi", damage/2);
      tell_room(environment(me),ob[i]->query("name")+"��ȫ��ð
���˹���Ũ�̣������ȼ�Ļ�ѣ�\n",ob[i]);
      tell_object(ob[i], "����û�����˺���˰�ľ�ʹ����\n")
;
      if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
     }
   }
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}

