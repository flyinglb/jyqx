// F_AUTOSAVE 
// autosave player's data

#include <ansi.h>

int autosave()
{
        int result,last_time,t;
        object me = this_object();

        if (!me) return 0;
        last_time = (int) me->query("last_save_time");
        t = time();
        if ( last_time + 300 > t )
                return 1;
        me->set("last_save_time",t);
        message("vision",HIG"�����̡������Զ������С���"NOR,me );
        result = me->save();
        if ( result )
                message("vision",HIY"��ϡ�\n"NOR, me );
        else
                message("vision",HIR"�洢ʧ�ܡ�\n"NOR, me );
        return 1;
}
