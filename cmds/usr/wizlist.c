// wizlist.c
//EDIT BY LANG 08/05/1999
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string *list;
        int my_level, i, j;
        int ch;
        object ob;
 
        list = sort_array(SECURITY_D->query_wizlist(), 1);
/*
write("\n[1;33m�� ��ӹȺ���� ��[1;37mĿǰ����ʦһ���� "+sizeof(list)+
" λ[0m(ǰ����[1;33m*[0m�߱���������)\n\n");
*/
        write(HIG"��"+MUD_NAME +""NOR "����ʦ��Ա��\n");
	write(HIW "�ѡ�"HIB"��������������������������������������������������������������"HIW"�ԡ�\n"NOR);
        my_level=wiz_level(me);
printf("[1;37m�� �� ����[0m");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(admin)")
        {     
                ch = ' ';
                if(ob=find_player(list[i]))
                        if(wizardp(me))
if(ob->visible(me) || wiz_level(ob) <= my_level || !find_player(list[i])->query_temp("invis"))
   ch = '*' ;
                printf("%c%-10s%s", ch, list[i], ((j++)%7==6) ? "\n  " : "");
        }
printf("\n[1;31m�� ʥ ����[0m");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(arch)")
        {
                ch = ' ';
                if(ob=find_player(list[i]))
                        if(wizardp(me))
                        if(ob->visible(me) || wiz_level(ob) <= my_level)
                                ch = '*';
                printf("%c%-10s%s", ch, list[i], ((j++)%7==6) ? "\n  " : "");
        }
printf("\n[1;33m�� �� ����[0m");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(wizard)")
        {
                ch = ' ';
                if(ob=find_player(list[i]))
                        if(wizardp(me))
                        if(ob->visible(me) || wiz_level(ob) <= my_level)
                                ch = '*';
                printf("%c%-10s%s", ch, list[i], ((j++)%7==6) ? "\n  " : "");
        }
printf("\n[1;32m�� �� ����[0m");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(apprentice)")
        {
                ch = ' ';
                if(ob=find_player(list[i]))
                        if(wizardp(me))
                        if(ob->visible(me) || wiz_level(ob) <= my_level)
                                ch = '*';
                printf("%c%-10s%s", ch, list[i], ((j++)%7==6) ? "\n  " : "");
        }
printf("\n[1;36m�� ħ ����[0m");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(immortal)")
                printf("%c%-10s%s", (find_player(list[i])) ? ch:' ', list[i], ((j++)%7==6
) ? "\n  " : "");
        write(HIW "\n�ѡ�"HIB"������������������������������������������"HIY"��ӹȺ����"HIB"����������"HIW"�ԡ�\n"NOR);
	printf("Ŀǰ���У�%sλ��ʦ��ǰ����[1;33m*[0m�߱��������ϣ���",chinese_number(sizeof(list)-1));
        write("\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
ָ���ʽ��wizlist
ָ��˵����
           ��ָ�������鿴Ŀǰ�ܹ��ж��ٸ���ʦ��
HELP
    );
    return 1;
}

