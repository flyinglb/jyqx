// prostitute.c
#include <condition.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if (duration < 1) return 0;
   if (file_name(environment(me))!="/d/city/lichunyuan2")
   {
   tell_object(me,HIY"����Ժ�깫����������ߣ�����������ȥ�����ȥ�ӿͣ�\n"NOR);
      message_vision(CYN"����Ժ�깫ͻȻ���֣����ɷ�˵������$N���ߡ�\n"NOR,me);
      me->move("/d/city/lichunyuan2");
   }
   me->apply_condition("prostitute", duration - 1);
   return CND_CONTINUE;
}
