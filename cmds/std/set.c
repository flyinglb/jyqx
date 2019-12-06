// set.c
// modified by Eatdami@MX (10/05/2000)
 
#define MAX_ENV_VARS    20

#include <ansi.h>

inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
        int i;
        string term, *terms, *wiz_only,*valid_env;
        mixed data;
        string data0;
        mapping env;
 
        wiz_only = ({"invisibility", "immortal"});
        valid_env= ({"wimpy","brief","no_fight_msg","no_tell","no_teach",
                        "no_accept","public"});
 
        if( me != this_player(1) ) return 0;
 
        env = me->query("env");
 
        if( !arg || arg=="" ) {
                write("��Ŀǰ�趨�Ļ��������У�\n");
                if( !mapp(env) || !sizeof(env) )
                        write("\tû���趨�κλ���������\n");
                else {
                        terms = keys(env);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-20s  %O\n", terms[i], env[terms[i]]);
                }
                return 1;
        }
 

        if( sscanf(arg, "%s %s", term, data)!=2 ) {
                term = arg;
                data = "YES";
        }
        
        if( term && term!="" ) {
                if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
                        return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");
           data0 = data;        /* save string* data */
           sscanf(data, "%d", data);
//added by long,Ϊ�˱���ĳЩδ֪��bug
             if ( wiz_level(me)==0  && member_array(term,valid_env ) == -1) {
		log_file("set_error",sprintf("%s(%s) try set %s on %s.\n",me->query("name"),me->query("id"),term,ctime(time()))); 
                return notify_fail("����������help settings�����������趨�Ļ���������\n");
	}
           if((wiz_level(me) == 0) && (member_array(term, wiz_only) != -1))
              return notify_fail("ֻ����ʦ��������趨��\n");

           me->set("env/" + term, data);
         
          printf("�趨����������%s = %O%s\n", term, data,NOR);
           return 1;
        }
        return help();
}
 
int help()
{
        write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"������ֵ��Ϊ�ַ������ɲ��� nick �仯��ɫ.
for example : set msg_min, msg_mout, msg_home , etc.
 
ȡ�������趨���� unset ָ�
 
�������Щ�������������趨����� help settings��
TEXT
        );
        return 1;
}
