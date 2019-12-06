// dir.c (ls)
// create by byp@jyqxz 2000/09/16

inherit F_CLEAN_UP;
#include <ansi.h>

string dir_info(string dir_path, string wildcard_str, int flag_dir, int flag_sub, int flag_lon);
string sub_dir_info(string sub_dir_path, string wildcard_str, int flag, int flag_lon);
string filter_arg(string cwd, string filt_path, int flag);

int do_match(string str, string substr);
int files_cont, dirs_cont, sub_dirs_cont, sub_files_cont;

int main(object me, string arg)
{
        string temp_path, dir_path, wildcard_str, str;
        int flag_pag, flag_dir, flag_sub, flag_lon;

        files_cont = 0; dirs_cont = 0;
        
        if(!arg || arg == " ") {
                dir_path = me->query("cwd");
        } else {//����ֽ�д��̫��
                if(arg == "/") dir_path = "/";
                else{
                        if(sscanf(arg, "-%s", str)) {//�ֽ����
                                temp_path = me->query("cwd");
                                if(strsrch(str,"p") != -1) flag_pag = 1;
                                if(strsrch(str,"d") != -1) flag_dir = 1;
                                if(strsrch(str,"l") != -1) flag_lon = 1;
                                if(strsrch(str,"s") != -1) flag_sub = 1;
                        } else if(sscanf(arg, "%s %s", temp_path, str) == 2) {
                                if(strsrch(str,"-p") != -1) flag_pag = 1;
                                if(strsrch(str,"-d") != -1) flag_dir = 1;
                                if(strsrch(str,"-l") != -1) flag_lon = 1;
                                if(strsrch(str,"-s") != -1) flag_sub = 1;
                } else temp_path = arg;

                        dir_path = filter_arg(me->query("cwd"), temp_path, 0);
                        wildcard_str = filter_arg(me->query("cwd"), temp_path, 1);
                }
        }
        write("debug message:"+arg+" "+flag_pag+" "+flag_dir+" "+flag_sub+" "+flag_lon+
              " "+temp_path+" "+dir_path+" "+wildcard_str+"\n");
        if(file_size(dir_path) == -1)
                return notify_fail("û���ҵ����ļ���Ŀ¼��\n");
        str = dir_info(dir_path, wildcard_str, flag_dir, flag_sub, flag_lon);
        if(!flag_pag) write(str);
        else me->start_more(str);
        
        return 1;
}

string dir_info( string dir_path, string wildcard_str, int flag_dir, int flag_sub, int flag_lon )
{
        int i, j, k , w, col, wildcard, size;
        string str;
        mixed *info;
        
        info = get_dir(dir_path,-1);
        str = "Ŀ¼��"+ dir_path +"\n";
        i = sizeof(info); w = 0; size = 0;

        if(nullp(wildcard_str)) wildcard = 0;
        else wildcard = 1;
        
        while(i--) {
                if( (info[i][1]==-2)&&(strlen(info[i][0])>w) )w = strlen(info[i][0]) + 1;
                if(strlen(info[i][0])>w) w = strlen(info[i][0]) + 1;
        }
         col = 70 / (w+6);
        
        if (sizeof(info))//Ŀ¼
                for(i=0, k=0, j=sizeof(info); i<j; i++) {
                        if(info[i][1] == -1) {k++; continue;}
                        if(info[i][1] != -2) {k++; continue;}
                        if(wildcard && !do_match(info[i][0], wildcard_str) ) {k++; continue;}
                        dirs_cont ++;
                        if(!flag_lon) {
                                str += sprintf(WHT"["NOR"%-*s"WHT"]"NOR"%4s%s",
                                       w+1,info[i][0]," ",((i-k+1)%col)?"  ":"\n");
                        } else {
                                str += sprintf(" %-*s %8s    %s", 
                                       w,info[i][0],WHT"   <DIR>"NOR,ftime(5,info[i][2])+"\n");
                        }
                }
       if (sizeof(info)&& !flag_dir)//�ļ�
                for(i=0, k=0, j=sizeof(info); i<j; i++) {
                        if(info[i][1] == -1) {k++; continue;}
                        if(info[i][1] == -2) {k++; continue;}
                        if(wildcard && !do_match(info[i][0], wildcard_str) ) {k++; continue;}
                        files_cont ++; size += info[i][1];
                        if(!flag_lon) {
                                str += sprintf(" %-*s %4s%s", 
                                       w,info[i][0]+(find_object(dir_path+info[i][0])?"*":" "),
                                       ""+(info[i][1]/1024+1), " ",((i-k+1)%col)?"  ":"\n");
                        } else {
                                str += sprintf(" %-*s %8s    %s", 
                                       w,info[i][0]+(find_object(dir_path+info[i][0])?" *":" "),
                                       ""+(info[i][1]), ftime(5,info[i][2])+"\n");
                        }
                }
        str += "\n\t\t\t\t\t"WHT+files_cont+NOR" file(s)  "WHT+size+NOR
               "  bytes  \n\t\t\t\t\t "WHT+dirs_cont+NOR"  dir(s)\n";
        if(flag_sub == 1)//��Ŀ¼
                for(i=0;i<sizeof(info);i++) {
                        if(info[i][1] == -1) continue;
                        if(info[i][1] != -2) continue;
                        //str += sub_dir(dir_path + info[i][0] + "/", flag_dir);
                        str += sub_dir_info(dir_path + info[i][0] + "/",wildcard_str , 1, flag_lon);//ǿ��ֻ��ʾĿ¼��
                }
        return str += "\n";
}

string sub_dir_info(string dir_path, string wildcard_str, int flag, int flag_lon)
{
        int i, j, k, w, col, wildcard, size;
        string str;
        mixed *info;

        info = get_dir(dir_path,-1); str = "Ŀ¼��"+ dir_path +"\n"; 
        i = sizeof(info); w = 0; sub_dirs_cont = 0; sub_files_cont = 0; size = 0;
        
        if(nullp(wildcard_str)) wildcard = 0;
        else wildcard = 1;
        
        while(i--) {
                if (strlen(info[i][0])>w) w = strlen(info[i][0]) + 1;
        }
        col = 70 / (w+7);
        if (sizeof(info))//Ŀ¼
                for(i=0, k=0, j=sizeof(info); i<j; i++) {
                        if(info[i][1] == -1) {k++; continue;}
                        if(info[i][1] != -2) {k++; continue;}
                        if(wildcard && !do_match(info[i][0], wildcard_str) ) {k++; continue;}
                        sub_dirs_cont ++; 
                        if(!flag_lon) {
                                str += sprintf(WHT"["NOR"%-*s"WHT"]"NOR"%4s%s",
                                       w,info[i][0]," ",((i-k+1)%col)?"  ":"\n");
                        } else {
                                str += sprintf(" %-*s %8s    %s", 
                                       w,info[i][0],WHT"   <DIR>"NOR,ftime(5,info[i][2])+"\n");
                        }
                }
        if (sizeof(info)&& !flag)//�ļ�
                for(i=0, k=0, j=sizeof(info); i<j; i++) {
                        if(info[i][1] == -1) {k++; continue;}
                        if(info[i][1] == -2) {k++; continue;}
                        if(wildcard && !do_match(info[i][0], wildcard_str) ) {k++; continue;}
                        sub_files_cont ++; size += info[i][1];
                        if(!flag_lon) {
                                str += sprintf(" %-*s %4s%s", 
                                       w,info[i][0]+(find_object(dir_path+info[i][0])?"*":" "),
                                       ""+(info[i][1]/1024+1), " ",((i-k+1)%col)?"  ":"\n");
                        } else {
                                str += sprintf(" %-*s %8s    %s", 
                                       w,info[i][0]+(find_object(dir_path+info[i][0])?" *":" "),
                                       ""+(info[i][1]), ftime(5,info[i][2])+"\n");
                        }
                }
        str += "\n\t\t\t\t\t"WHT+files_cont+NOR" file(s)  "WHT+size+NOR
               "  bytes  \n\t\t\t\t\t "WHT+dirs_cont+NOR"  dir(s)\n";
        for(i=0;i<sizeof(info);i++) {
                if(info[i][1] == -1) continue;
                if(info[i][1] != -2) continue;
                //str += sub_dir(sub_dir + info[i][0] + "/", flag);
                str += sub_dir_info(dir_path + info[i][0] + "/", wildcard_str, 1, flag_lon);//ǿ��ֻ��ʾĿ¼��
                str += "\n";
        }
        return str;
}

string filter_arg(string cwd, string filt_path, int flag)
{
        string *temp, new_path;
        int i, j, k, wildcard;
        
        if(flag) {//��֤ filt_path Ϊ��ֵ
                if(nullp(filt_path)) return filt_path;
                if(filt_path == "") return new_path;
                if((strsrch(filt_path,"*")==-1) && (strsrch(filt_path,"?")==-1)) return new_path;
        }
        temp = explode(filt_path,"/");
        for(i=0;i<sizeof(temp);i++) {
                if( (strsrch(temp[i],"*")== -1)&&(strsrch(temp[i],"?")== -1) ) continue;
                wildcard = 1;
                new_path = "";
                if(flag) {
                        for(k=sizeof(temp);i<k;i++) new_path += temp[i]+"/"; 
                        new_path = new_path[0..strlen(new_path)-2];
                        return new_path;
                }
                for(j=0;j<i;j++) new_path += temp[j]+"/"; 
                break;
        }
        if(!wildcard) new_path = filt_path;
        new_path = resolve_path(cwd, new_path);
        i = strlen(new_path)-1;
        if( (new_path != "/")&&(new_path[i..i] != "/") ) new_path += "/";//ȷ��Ŀ¼��β�� '/'
        return new_path;
}

int do_match(string str, string substr)
{
        int i;

        for(i = 0;i < sizeof(substr);i++) {
                if(i >= sizeof(str) )   return 0;
                if(substr[i..i] == "?") continue;
                if(substr[i..i] == "*") {//����Ҫ��ǿ
                        if((substr[i-1..i-1] == "?")&&(str[i-1..i-1] != substr[i-1..i-1])) return 1;
                        if((substr[i-1..i-1] != "?")&&(str[i-1..i-1] == substr[i-1..i-1])) return 1;
                }
                if(str[i] != substr[i]) return 0;
        }
        return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ: dir [<·����>] [-p] [-d] [-s] [-l]
 
�г�Ŀ¼�����е���Ŀ¼������, ���û��ָ��Ŀ¼, ���г���ǰ����
Ŀ¼�����ݣ����г��ĵ�����ǰ���ʾ * �ŵ����Ѿ�����������
֧��ͨ��� '*' '?' * ���������ַ� ? ����һ���ַ�

������
 -p(page)       ��ҳ��ʾ
 -d(dir)        ֻ��ʾĿ¼
 -s(subdir)     ������Ŀ¼(Ϊ��ʡ��Դ��ֻ��ʾ��Ŀ¼)
 -l(long)       ��ʾ�������Ϣ
 
ʵ��:
ls /            ���г�����λ춸�Ŀ¼�µĵ�������Ŀ¼.
ls / -d         ���г�����λ춸�Ŀ¼������Ŀ¼. 
ls / -p -l      ���Գ���Ϣ��ҳ��ʾ�ļ���Ŀ¼��

HELP
    );
    return 1;
}
