// time.c
// modified by wind

#include <localtime.h>
#define C(x) CHINESE_D->chinese_number(x)
inherit F_CLEAN_UP;
int main(object me, string arg)
{
      mixed *local = localtime(time());
        write("������̶ʱ���ǣ�" + NATURE_D->game_time() + "��\n");
      write("��ʵ����ʱ���ǣ���Ԫ"+sprintf("%s��%s��%s��%sʱ%s��%s��",C(local[LT_YEAR]),C(local[LT_MON]+1),C(local[LT_MDAY]),C(local[LT_HOUR]),C(local[LT_MIN]+1),C(local[LT_SEC]+1))+"\n");
        return 1;
}
int help(object me)
{
     write(@HELP
ָ���ʽ: time
���ָ������(��)֪�����ڵ�ʱ����
HELP
    );
    return 1;
}
