//color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
        tell_object(me,MAG"��"HIY"ɫ�ʾ�����������"MAG"��\n\n"NOR);
        tell_object(me,
"  ��ɫ- BLK"BLK"������                       BBLK"BBLK"������"NOR"\n"
"  ��ɫ- RED"RED"������"NOR" HIR"HIR"������"NOR" HBRED"HBRED"������"NOR" BRED"BRED"������"NOR"\n"
"  ��ɫ- GRN"GRN"������"NOR" HIG"HIG"������"NOR" HBGRN"HBGRN"������"NOR" BGRN"BGRN"������"NOR"\n"
"  ��ɫ- YEL"YEL"������"NOR" HIY"HIY"������"NOR" HBYEL"HBYEL"������"NOR" BYEL"BYEL"������"NOR"\n"
"  ��ɫ- BLU"BLU"������"NOR" HIB"HIB"������"NOR" HBBLU"HBBLU"������"NOR" BBLU"BBLU"������"NOR"\n"
"  ��ɫ- MAG"MAG"������"NOR" HIM"HIM"������"NOR" HBMAG"HBMAG"������"NOR" BMAG"BMAG"������"NOR"\n"
"  ��ɫ- CYN"CYN"������"NOR" HIC"HIC"������"NOR" HBCYN"HBCYN"������"NOR" BCYN"BCYN"������"NOR"\n"
"  ��ɫ- WHT"WHT"������"NOR" HIW"HIW"������"NOR" HBWHT"HBWHT"������"NOR"\n");
        return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : color

���ָ���������֪����Ϸ�и���ɫ�ʵ�ANSI������Ԫ��ɫ�ʵ�
�������Ӷ�������ѡ�������ɫ�ʡ�

HELP
    );
    return 1;
}
