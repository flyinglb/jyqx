// written by atu for SJFY
#include <dbase.h>
inherit F_DBASE;
int help(object);

int main(object  me,  string  arg)
{
	mapping list,tlist;
	mixed *klist,*tlist2;
	object ob,ob1;
        string text,id,spec;

	int loop;

	seteuid(geteuid(me));
	if(arg){
		sscanf(arg,"%s %s",  spec,  arg);
		if(arg=="-t"||arg=="-d"){
              	spec=arg;
			arg=0;
		}
		if(spec && spec!="-d" && spec!=  "-t"){
			arg = spec + " " +arg;
       	       spec  =  0;
		}
	}
	if(!arg||arg=="")
		ob =  environment(me);
	else if(sscanf(arg,  "%s in %s",arg,id)  ==  2)	{
		ob1=present(id,environment(me));
		if  (!ob1) ob1=present(id,  me);
		if  (!ob1)  return notify_fail  ("�����޴�����:  "+id+"\n");
		if  (!ob=present(arg,  ob1))
			return notify_fail ("�����������޴����:  "+arg+"\n");
      }else if (arg== "me"){
		ob=me;
      }else{
		arg = lower_case(arg);
		ob = present(arg,  environment(me));
		if (!ob)  ob  =  find_player(arg);
		if  (!ob)  ob  =  find_living(arg);
		if (!ob)  ob  =  present(arg,  me);
		if(!ob) return notify_fail("Data:  �޷��ҵ������:  "+arg+"��\n");
	}
	list  =  (mapping)ob->query_entire_dbase();
	tlist  =  (mapping)ob->query_entire_temp_dbase();
	if( (!list  ||  !mapp(list))  &&  (!tlist  ||  !mapp(tlist)))
		return  notify_fail("Data:  �������û���κε����ϡ�\n");
	if  (sizeof(list))
	{
		klist  =  keys(list);
		klist  =  sort_array(klist,  "sort_keys",  this_object());
	}
	if  (sizeof(tlist))
	{
        	tlist2  =  keys(tlist);
		tlist2  =  sort_array(tlist2,  "sort_keys",  this_object());
	}
  
	//  if(!member_group(geteuid(this_player()),  "admin"))
	//	klist  =  filter_array(klist,  "filter_props",  this_object(),  ob);
	if(!klist  ||  !sizeof(klist))
		return  notify_fail("Data:  �������û�д����κ����ϡ�\n");
	if  (!spec  ||  spec  ==  "-d")  {
		text  =  "Object  :  "  +  base_name(ob)  +  ".c\n";
		for(loop=0;  loop<sizeof(klist);  loop++)    {
			if(strlen(klist[loop])  >  7)    text  +=  klist[loop]  +  "\t:  ";
			else  text  +=  klist[loop]  +  "\t\t:  ";
			text  +=sprintf("%O  \n",list[  klist[loop]  ]);
		}
		text +="\n�ܹ���  "  +  sizeof(klist)  +  "  ����������ϡ�\n\n";
      }
      else  text  =  "";
  
      if  (!spec  ||  spec  ==  "-t")  {

          text  +=  "TEMP  DATA  :\n\n";
  
          for(loop=0;  loop<sizeof(tlist2);  loop++)    {
              if(strlen(tlist2[loop])  >  7)    text  +=  tlist2[loop]  +  "\t:  ";
              else  text  +=  tlist2[loop]  +  "\t\t:  ";
                  text  +=sprintf("%O  \n",tlist[  tlist2[loop]  ]);  
          }
  
          text  +=  "\n�ܹ���  "  +  sizeof(tlist2)  +  "  ���ݴ�����ϡ�\n\n";
      }
	me->start_more(  text  );
      //  tmp  =  explode(text,  "\n");
      //  for(loop=0;  loop<sizeof(tmp);  loop++)      write(tmp[loop]+"\n");
      return  1;
}
  
//This function is used to sort the key array.
int sort_keys(string one,string two)

{
	return  strcmp(one,  two);
	}
  
//This function strips out the secured props from the data array.
int  filter_props(string  prop,  object  target)

{
//      if(member_array((int)target->query_permission(prop),
//	({  MASTER_ONLY,  PRIVATE,  OWNER_ONLY  }))  !=  -1)      return  0;
	return  1;  
}

int help(object  me)
{
    write(  @LONG
ָ���ʽ:  data  [-t|-d]  [���|���|here]  [in  ��һ�����]
ָ���:  data			<--  ���Լ�������  data  base
           data  -t			<--  ���Լ����ݴ�����
	    data  -d			<--  ���Լ�����������
	    data  -t  here		<--  �����ڷ������ʱ����
	    data  wade		<--  ��  wade  ������(�����)����������
	    data  board		<--  �����ӵ�����
	    data  cloth  in  wade	<--  ��  wade  ���ϵ�  cloth  ������
ָ��˵��:
	������������Թۿ���ָ����������ϣ��ҽ�����  more  �ķ�ʽ
��������û��ָ���������Զ���ʹ����Ϊ���������е�  -t  ѡ�������
ʾ��ʱ����,  -d  ѡ�����ֻ��ʾ���ñ���,  ��Ҫ���Ķ����������һ�
�κ����.
LONG);
	return  1;
}
  
