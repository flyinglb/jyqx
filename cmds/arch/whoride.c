/*  <SecCrypt CPL V3R05>  */
 
//  by  snowcat  6/21/1997
//  whohave.c

inherit  F_CLEAN_UP;

mixed  main(object  me,  string  arg,  int  remote)
{
	object  *ulist;
	int  i;

	ulist  =  users();
	i  =  sizeof(ulist);
	while  (i--)  {
		object  who  =  ulist[i];
		object  ridee  =  ulist[i]->query_temp("ridee");
		
		if  (!  ridee)
			continue;
		if  (ridee->query_temp("rider")  !=  who)  {
			continue;
		}	
		write  ("    ");
		write  (who->query("name")+"("+who->query("id")+")");
		write  (ridee->query("ride/msg")+"��");
		write  (ridee->query("name")+"("+ridee->query("id")+")");
		write  ("�ϡ�\n");
	}
	return  1;
}

int  help  (object  me)
{
                write(@HELP
ָ���ʽ  :  whoride  
  
���г�Ŀǰ�����������ҡ�
  
  
HELP
);
                return  1;
}
