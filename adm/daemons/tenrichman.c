//������/adm/daemons/tenrichmand.c������һЩ����������

//tenrichmand.c
////////////////////////////////////////////////////////////////////////////////
//
//1997.5.20 finished
//by maxim@nju_mud
//1997.12.1��������
////////////////////////////////////////////////////////////////////////////////
//
#include <login.h>
string *gaoshou_status;
string gaoshou_id_min;
string gaoshou_name_min;
int gaoshou_exp_min;
int gaoshou_number_min;
string gaoshou_title_min;

void create()
{
seteuid(geteuid());
}

// This function returns the status of an uid.
int set_rich(mixed ob, int exp)
{
string uid, gaoshou_id,gaoshou_name,gaoshou_title;
string now_id,now_name,now_title;
string *gaoshoulist,gaoshoulist2;
int i,j,gaoshou_exp,now_exp;

if( userp(ob) ) uid = getuid(ob);
else if(stringp(ob)) uid = ob;
else
return 0;



gaoshoulist = explode(read_file(RICHMAN), "\n");

//RICHMAN is the file to be read
//��/include/login.h���ж��塣
//����û���ж��ļ�����Ĵ��룬��������Ҫ��֤
//�ļ��ĸ�ʽ��ȷ��

gaoshou_status = allocate(sizeof(gaoshoulist));
for(i=0; i<10; i++) {
if( sscanf(gaoshoulist[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,
gaoshou_exp)!=4 ) continue;
gaoshou_status[i] = (string)gaoshou_id+" "+
(string)gaoshou_name+" "+
(string)gaoshou_title+" "+
(string)gaoshou_exp;
}

for(i=0; i<9; i++){
for(j=0;j<9-i;j++){
if( gaoshou_status[j][0]=='#'
|| sscanf(gaoshou_status[j], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if( gaoshou_status[j+1][0]=='#'
|| sscanf(gaoshou_status[j+1], "%s %s %s %d", now_id,now_name,now_title,now_exp)
!=4 ) continue;
if(gaoshou_exp < now_exp){
gaoshou_status[j]=now_id+" "+now_name+" "+now_title+" "+(string)now_exp;
gaoshou_status[j+1]=gaoshou_id+" "+gaoshou_name+" "+gaoshou_title+" "+(string)gaoshou_exp;
}
}
}

gaoshou_exp_min=3000000000000;
//����˵�ǮҪ���������Ŀ
sscanf(gaoshou_status[4], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp) ;
gaoshou_exp_min=gaoshou_exp;

//ȡ�ùؼ�����Сֵ��������Ϣ
for(i=0; i<10; i++) {
if( sscanf(gaoshou_status[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if(gaoshou_exp < gaoshou_exp_min){
gaoshou_id_min=gaoshou_id;
gaoshou_number_min=i;
gaoshou_name_min=gaoshou_name;
gaoshou_title_min=gaoshou_title;
gaoshou_exp_min=gaoshou_exp;
}
}

for(i=0; i<10; i++) {
if( sscanf(gaoshou_status[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if(uid == gaoshou_id){
gaoshou_id_min=gaoshou_id;
gaoshou_number_min=i;
gaoshou_name_min=gaoshou_name;
gaoshou_title_min=gaoshou_title;
gaoshou_exp_min=gaoshou_exp;
break;
}
}


gaoshou_name=(string)ob->query("name");
gaoshou_title=(string)ob->query("title");

//�����Ѿ����ڵ��˵����ݣ����߰���Сֵ���˵��������
if( (int)exp > (int)gaoshou_exp_min || uid == gaoshou_id) {
gaoshou_status[gaoshou_number_min]=
uid+" "+gaoshou_name+" "+gaoshou_title+" "+ (string)exp;

//���������Ѿ��ı䣬�˴�����������
for(i=0; i<9; i++){
for(j=0;j<9-i;j++){
if( gaoshou_status[j][0]=='#'
|| sscanf(gaoshou_status[j], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if( gaoshou_status[j+1][0]=='#'
|| sscanf(gaoshou_status[j+1], "%s %s %s %d", now_id,now_name,now_title,now_exp) !=4 ) continue;
if(gaoshou_exp < now_exp){
gaoshou_status[j]=now_id+" "+now_name+" "+now_title+" "+(string)now_exp;
gaoshou_status[j+1]=gaoshou_id+" "+gaoshou_name+" "+gaoshou_title+" "+(string)gaoshou_exp;

}
}
}
//����Ϊд�ļ�
for(gaoshoulist2 = "", i=0; i<10; i++){
if( gaoshou_status[i][0]=='#'
|| sscanf(gaoshou_status[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;

gaoshoulist2+= gaoshou_id+" "+gaoshou_name+" "+gaoshou_title+" "+(string)gaoshou_exp+"\n";
}

rm(RICHMAN);
write_file(RICHMAN, gaoshoulist2);

//��¼������Ϣ
log_file( "static/tenrich", capitalize(uid)
+ " become ʮ����֮һ: " + exp + " on " + ctime(time()) + "\n" );

//׼�����ش������������ֵ
for(i=0; i<10; i++) {
if( sscanf(gaoshou_status[i], "%s %s %s %d", gaoshou_id,gaoshou_name,gaoshou_title,gaoshou_exp)!=4 ) continue;
if(uid == gaoshou_id){
break;
}
}

return (i+1);
}
else return 0;

}

