inherit F_CLEAN_UP; 

int updatefile(object me,string file); 

int main(object me, string arg) 
{ 

	int i, j; 
	string dir; 
	mixed *file; 
         
        seteuid( geteuid(me) ); 

	dir = resolve_path(me->query("cwd"), arg); 
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) 
		dir += "/"; 
	file = get_dir(dir, -1); 
	if( !sizeof(file) ) {
		if (file_size(dir) == -2) 
			return notify_fail("Ŀ¼�ǿյġ�\n"); 
	else 
		return notify_fail("û�����Ŀ¼��\n"); 
	} 

	i = sizeof(file); 

	while(i--) { 
		if (file[i][1]==-2) 
			file[i][0] += "/"; 
	} 
	write("Ŀ¼��" + dir + "\n"); 

	if (sizeof(file)) 
	for(i=0, j = sizeof(file); i<j; i++) 
	{ 
                  if (file[i][1]!=-2 && sscanf(file[i][0], "%*s.c")  
                     && file[i][0][strlen(file[i][0])-1]=="c"[0] 
                     && file[i][0][strlen(file[i][0])-2]=="."[0]) 
                  	updatefile(me,dir+file[i][0]);  
                  else if (file[i][1]==-2) 
			call_other(__FILE__,"main",me,dir+file[i][0]);
	} 
	else write("    û���κε�����\n"); 
	write("\n"); 

	return 1; 
} 



int updatefile(object me,string file) 
{ 
    object obj,*inv; 
    int i; 
    string err; 
	me->set("cwf", file); 

if (obj = find_object(file)) { 
if( obj==environment(me) ) { 
if( file_name(obj)==VOID_OB ) 
return notify_fail("�㲻���� VOID_OB �����±��� VOID_OB��\n"); 
inv = all_inventory(obj); 
i = sizeof(inv); 
while(i--) 
if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1); 
else inv[i] = 0; 
} 
destruct(obj); 
} 

if (obj) return notify_fail("�޷�����ɳ�ʽ�롣\n"); 

    write("���±��� " + file + "��"); 
err = catch( call_other(file, "???") ); 
if (err) 
printf( "��������\n%s\n", err ); 
else { 
write("�ɹ���\n"); 
if( (i=sizeof(inv)) && (obj = find_object(file))) { 
while(i--) 
if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1); 
} 
} 
} 

int help(object me) 
{ 
write(@HELP 
ָ���ʽ: updir [<·����>] 
  
��Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ��ʹ�õ�ǰĿ¼ 

  
����: 
updir /adm �Ὣ����λ춸�/admĿ¼�µĵ����������. 
  
HELP 
); 
return 1; 
} 

