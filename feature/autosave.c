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
        message("vision",HIG"【存盘】档案自动更新中……"NOR,me );
        result = me->save();
        if ( result )
                message("vision",HIY"完毕。\n"NOR, me );
        else
                message("vision",HIR"存储失败。\n"NOR, me );
        return 1;
}
