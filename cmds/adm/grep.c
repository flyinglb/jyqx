// atu@sjfy
inherit F_CLEAN_UP;
int grep(string dir,string pat);

int main(object me,string arg)
{
        string dir,pat;

        if (!arg) return
                notify_fail("ָ���ʽ: grep <·��> <�ַ���> \n");

        dir = me->query("cwd");
        pat = arg;
        if (sscanf(arg, "%s %s", dir, pat)==2 )
        {
                dir = resolve_path(me->query("cwd"), dir);
        }

        if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";

        printf("������%s��Ѱ��%s\n",dir,pat);

        grep(dir,pat);
        return 1;
}

int grep(string dir,string pat)
{
        int i, j;
        mixed *file;
        string file2,dirstr;

        file = get_dir(dir, -1);
        if( !sizeof(file) )
        {if (file_size(dir) == -2) return notify_fail("Ŀ¼�ǿյġ�\n");
                else
                return notify_fail("û�����Ŀ¼��\n");
        }

        i = sizeof(file);
        if (sizeof(file))

                for(i=0, j = sizeof(file); i<j; i++) {
                                if (file[i][1] != -2)   {
                                file2 = read_file(dir+file[i][0]);
                                if (strsrch(file2,pat) != -1) write(dir+file[i][0]+"\n");
                        } 
                        else {  dirstr=dir+file[i][0]+"/";
//                              write(dirstr+"\n");
                                grep(dirstr,pat);}
                        }
        return 1;       
}

int help(object me)
{
        write(@HELP
ָ���ʽ: grep [<·����>] [<����>]
 
��ָ��Ŀ¼�����еĵ�������ָ�����ַ���, ���û��ָ��Ŀ¼, 
��ǰ����Ŀ¼Ϊָ��Ŀ¼��
 
����:
'grep /' �����ĵ�.
 
HELP
    );
    return 1;
}
