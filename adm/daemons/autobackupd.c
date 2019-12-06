// autobackupd.c
// create by byp 2000/06/28

#include <ansi.h>

inherit F_DBASE;

#define B_PATH ({DATA_DIR + "login/", DATA_DIR + "user/",})
#define B_DIR "/backup/"
#define B_AMOUNT 10
#define B_DAY 30
#define NEXT_BACKUP "/log/NEXTBACKUP"

int next_backup_time();
void backup_delete(string current_delete_path);
void backup_start(string current_backup_path);
void backup_check();
void delete_check();
void update_start();
void delete_start();
void set_next_backup_time(int times);

int next, now_times, dir_amount, file_amount, erro_amount;
string *current_dir, *backup_path, delete_path, backup_to;

void create()
{
        seteuid(getuid());
        set("channel_id", "自动备份");
        backup_check();
        delete_check();
}

void backup_check()
{
        remove_call_out("backup_check");
        
        now_times = time() /3600 /24;        
        next = next_backup_time() /3600 /24;
        
        if ( (next - now_times) <= 0 ) update_start();
        
        call_out("backup_check",3600 * 24);
}
void delete_check()
{
        remove_call_out("delete_check");

        if(sizeof(get_dir(B_DIR))>B_AMOUNT) delete_start();

        call_out("delete_check",3600 * 24);
}

void update_start()
{
        int i, l;
        
        dir_amount = 0;
        file_amount = 0;
        erro_amount = 0;
        backup_path = B_PATH;
        backup_to = B_DIR + now_times + "";
        
        if(file_size(B_DIR) == -1)
                mkdir(B_DIR);
        
        mkdir(backup_to);

        for (i =0; i<sizeof(backup_path); i++) {
                current_dir = get_dir(backup_path[i]);

                if (!sizeof(current_dir)) {
                        erro_amount++;
                        continue;
                }
        
                for(l=0; l<strlen(backup_path[i]); l++) {
                        if(backup_path[i][l..l] == "/")
                                if( mkdir(backup_to + backup_path[i][0..l-1]) )
                                        dir_amount++;
                }
                
                backup_start(backup_path[i]);
        }
      
        set_next_backup_time(time() + (3600 * 24 * B_DAY));
/*
        CHANNEL_D->do_channel(this_object(), "sys",
        sprintf("共处理%s个目录，%s个文件。其中有%s个文件备份失败", 
        CHINESE_D->chinese_number(dir_amount), CHINESE_D->chinese_number(file_amount), CHINESE_D->chinese_number(erro_amount)) );
*/
        return ;
}
void delete_start()
{
        int backup_list, list, j, k;
        
        backup_path = get_dir(B_DIR);
        backup_list = 0;
        list = time();
        j = sizeof(backup_path);
        
        while(j>(B_AMOUNT-1)) {
                for (k = 0; k<sizeof(backup_path); k++) {
                        sscanf(backup_path[k],"%d", backup_list);
                        if (backup_list < list)
                                list = backup_list;
                }
                delete_path = B_DIR + list + "/";
                backup_delete(delete_path);
                j--;
        }
}
void backup_start(string current_backup_path)
{
        string *temp_dir;
        int z;
        
        temp_dir = get_dir(current_backup_path);
        for(z=0; z<sizeof(temp_dir); z++) {
                
                if(file_size(backup_to + current_backup_path + temp_dir[z]) > -1
                || file_size(backup_to + current_backup_path + temp_dir[z]) == -2)
                        continue;
                
                if(file_size(current_backup_path + temp_dir[z]) == -2) {
                        if(mkdir(backup_to + current_backup_path + temp_dir[z])) {
                                dir_amount++;
                                backup_start(current_backup_path + temp_dir[z] +"/");
                        } else {
                                erro_amount++;
                                continue;
                        }
                } else if(file_size(current_backup_path + temp_dir[z]) > -1){
                        if(cp(current_backup_path + temp_dir[z],backup_to + current_backup_path + temp_dir[z]))
                                file_amount++;
                        else
                                erro_amount++;
                }
        }
        return ;
}

void backup_delete(string current_delete_path)
{
        string *delete_dir;
        int z;

        delete_dir = get_dir(current_delete_path);

        if(!sizeof(delete_dir)) {
                if(file_size(current_delete_path) == -2) {
                        if(rmdir(current_delete_path))
                                dir_amount++;
                        else
                                erro_amount++;

                        return;
                }
        }
        
        for(z=0; z<sizeof(delete_dir); z++) {
                if(file_size(current_delete_path + delete_dir[z]) == -2)
                        backup_delete(current_delete_path + delete_dir[z] +"/");
                else if(file_size(current_delete_path + delete_dir[z]) > -1){
                        if(rm(current_delete_path + delete_dir[z]))
                                file_amount++;
                        else
                                erro_amount++;
                        }
        }
        return ;
}

int next_backup_time()
{
        string content, format;
        int times = 0;

        content = read_file(NEXT_BACKUP);
        
        if(!content)
                times = now_times * 3600 * 24;
        else
                sscanf(content, "%s %d", format, times);
        
        if(times == 0)
                times = now_times * 3600 * 24;

        return times;
}

void set_next_backup_time(int times)
{
        if(times == 0) return ;
        
        write_file(NEXT_BACKUP, sprintf("NEXT_BACKUP_DAY %d\n", times), 1);

        return;
}

