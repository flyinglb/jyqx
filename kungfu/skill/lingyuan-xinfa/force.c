// force.c
// Modified by Venus Oct.1997

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    int damage;

    me->add("force", - factor );
    damage = (int)me->query("force")/20 + factor
   - (int)victim->query("force")/25;

    if( damage < 0 ) {
   if( !me->query_temp("weapon")
   &&      random(victim->query_skill("force")) > me->query_skill("
force")/2 ) {
      damage = - damage;
      me->receive_damage( "qi", damage * 2 );
      me->receive_wound( "qi", damage );
      if( damage < 10 ) return "$N�ܵ�$n�����������ƺ�һ����
\n";
      else if( damage < 20 ) return "$N��$n���������𪬡��١���һ������������\n";
      else if( damage < 40 ) return "$N��$N������һ�����������ܵ�һ���ش�����������������\n";
      else return "$N��$n������һ����ǰһ�ڪ���������ɳ�����\n";
   }
   if( damage_bonus + damage < 0 ) return - damage_bonus;
   return damage;
    }

    damage -= victim->query_temp("apply/armor_vs_force");
    if( damage_bonus + damage < 0 ) return - damage_bonus;
    if( random(me->query_skill("force")) < damage )
   return damage;
}
