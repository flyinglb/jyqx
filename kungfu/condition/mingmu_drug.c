// mingmu_drug.c ��Ŀ��

#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("mingmu_drug", duration - 1);
        return 1;
}
