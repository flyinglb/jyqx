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
write("\n[1;33m¡ï ½ðÓ¹ÈºÏÀ´« ¡ï[1;37mÄ¿Ç°µÄÎ×Ê¦Ò»¹²ÓÐ "+sizeof(list)+
" Î»[0m(Ç°ÃæÓÐ[1;33m*[0mÕß±íÕýÔÚÏßÉÏ)\n\n");
*/
        write(HIG"¡ò"+MUD_NAME +""NOR "¡òÎ×Ê¦³ÉÔ±£º\n");
	write(HIW "¡Ñ¡Ô"HIB"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"HIW"¡Ô¡Ñ\n"NOR);
        my_level=wiz_level(me);
printf("[1;37m¡¾ Ìì ¡¿£º[0m");
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
printf("\n[1;31m¡¾ Ê¥ ¡¿£º[0m");
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
printf("\n[1;33m¡¾ ÏÉ ¡¿£º[0m");
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
printf("\n[1;32m¡¾ Éñ ¡¿£º[0m");
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
printf("\n[1;36m¡¾ Ä§ ¡¿£º[0m");
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])=="(immortal)")
                printf("%c%-10s%s", (find_player(list[i])) ? ch:' ', list[i], ((j++)%7==6
) ? "\n  " : "");
        write(HIW "\n¡Ñ¡Ô"HIB"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"HIY"½ðÓ¹ÈºÏÀ´«"HIB"©¤©¤©¤©¤©¤"HIW"¡Ô¡Ñ\n"NOR);
	printf("Ä¿Ç°¹²ÓÐ£º%sÎ»Î×Ê¦£¨Ç°ÃæÓÐ[1;33m*[0mÕß±íÕýÔÚÏßÉÏ£©¡£",chinese_number(sizeof(list)-1));
        write("\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
Ö¸Áî¸ñÊ½£ºwizlist
Ö¸ÁîËµÃ÷£º
           ±¾Ö¸ÁîÓÃÀ´²é¿´Ä¿Ç°×Ü¹²ÓÐ¶àÉÙ¸öÎ×Ê¦¡£
HELP
    );
    return 1;
}

