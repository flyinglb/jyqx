// heart_sense.c ĞÄÊ¶ÉñÍ¨
// Modified by Venus Oct.1997

#include <ansi.h>

//inherit SSERVER;

int conjure(object me, object target)
{
    if( !target || !target->is_character() )
      return notify_fail("ÄãÒª¶ÔË­Ê¹ÓÃĞÄÊ¶ÉñÍ¨£¿\n");
    if( target->is_corpse() )
      return notify_fail("À´²»¼°ÁË£¬Ö»ÓĞ»îÈË²ÅÄÜ¾ÈĞÑ¡£\n");

    if( (int)me->query("jingli") < 50 ) return notify_fail("ÄãµÄ¾«Á¦²»¹»£¡\n");
       me->add("jingli", -50);
       me->receive_damage("jing", 30);
       message_vision( HIY "$NÒ»ÊÖ·ÅÔÚ$nµÄÌìÁé¸ÇÉÏ£¬Ò»ÊÖÌùÔÚ$nµÄááĞÄ£¬±ÕÉÏÑÛ¾¦º»ºµÍÒ÷ ...\n" NOR,me, target );
    if( random(me->query("max_jingli")) > 100 )
       target->revive();
    else
       me->unconcious();
    if( me->is_fighting() )
       me->start_busy(3);
    return 1;
}

