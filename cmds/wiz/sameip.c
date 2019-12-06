// sameip.c
 
#include "/doc/help.h"
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	object *ob_list;
	string msg="";
	string subip;
	int i;
	if (!arg) 
	{
	ob_list = sort_array(users(),"sort_user",this_object());
	for(i=0;i<sizeof(ob_list);i++)
	msg += sprintf("%-10s %-10s %-20s %-20s\n",
		ob_list[i]->query("id"),
		ob_list[i]->query("name"),
		query_ip_number(ob_list[i]),
		query_ip_name(ob_list[i]));	
	me->start_more(msg);
	return 1;
	}
	if(!ob=find_player(arg))
	{
	msg = "���У�"+arg+"��IP����ҵ�ѶϢ��\n";
	subip=arg;
	}
	else
	{
	subip=query_ip_number(ob);
	msg="���У�"+subip+"��IP����ҵ�ѶϢ��\n";
	}
	ob_list = filter_array(users(),"select_user",this_object(),subip);
        for(i=0;i<sizeof(ob_list);i++)
        msg += sprintf("%-10s %-10s %-20s %-20s\n",
                ob_list[i]->query("id"),
                ob_list[i]->query("name"),
                query_ip_number(ob_list[i]),
                query_ip_name(ob_list[i]));
        me->start_more(msg);
        return 1;
}
int sort_user(object a, object b)
{
return strcmp(query_ip_number(a), query_ip_number(b));
} 
int select_user(object a, string subip)
{
if(strsrch(query_ip_number(a),subip) == -1) return 0;
else return 1;
}
int help(object me)
{
   write(@HELP
ָ���ʽ: sameip <id/arg/none>
����쿴�й�һ��IP������������ҡ�

HELP);
   return 1;
}
string tot_usr(object me)
{
	return chinese_number(sizeof(filter_array(users(),"select_user",this_object(),query_ip_number(me))));
}
