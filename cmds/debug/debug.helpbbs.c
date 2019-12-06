// help.c
// created by host ,98.8.20
#include <ansi.h>
#include <login.h>
#include "/doc/help.h"
inherit ITEM;
string *default_search = DEFAULT_SEARCH_PATHS;
string depart = read_file("/doc/help/menu/depart.menu");
string map = read_file("/doc/help/menu/map.menu");
string intro = read_file("/doc/help/menu/intro.menu");
string board = read_file("/doc/help/menu/board.menu");
void m_display();
void a_display();
void b_display();
void c_display();
void u_display();
void o_display();
void auto_load();
void view_main();
void view_main_1();
private void a(string arg, string register);
private void b(string arg, string register);
private void c(string arg, string register);
private void d(string arg, string register);
private void e(string arg, string register);
private void f(string arg, string register);
private void g(string arg, string register);
private void confirm_main_choice(string arg);
private void confirm_a_choice(string arg);
private void confirm_b_choice(string arg);
private void confirm_c_choice(string arg);
private void confirm_u_choice(string arg);
private void confirm_o_choice(string arg);
private void y(string arg, string register);
int check_user();
int check_nowait();
int wizlist();
int message();
int message1();
string age_string(int time);
int helpmore(string cmd, string *text, int line)
{
        int i,j;

        switch(cmd) {
         case "":
               for(i=line + 23; line<sizeof(text) && line<i; line++)
                   write(text[line] + "\n");
             if( line>=sizeof(text) ) {
                   printf("== ȫ����" HIY "%d%%" NOR " == (ENTER �����ϸ�ѡ��)",(line*100/sizeof(text)) );
                   check_user();
                   return 1; }
                   break; 
        case "b":
                   line = line - 46;
        if(line<-22) return 1;
        for(i=line + 23; line < i;line++)
                   write(text[line]+"\n");
                   break;
        case "q":
                   check_nowait();
                   return 1;
        }
           printf("== δ����� " HIY "%d%%" NOR " == (ENTER ������һҳ��q �뿪��b ǰһҳ)",(line*100/sizeof(text)) );
           input_to("helpmore", text, line);
}
int register()
{
   object me;
   me = this_player();
   if(!me->query("register")) {
         write(CLR"\n");
         write(HIW"��ʹ�����趨��        "HIY"��"+MUD_NAME+"ע�ᵥ��\n"NOR);
         write("\n");
         write(YEL"Ŀǰѡ��\n\n"NOR);
         write(HIW"    ���Ĵ���     : "NOR);
         input_to((:a:),this_player());
         return 1;
        }
    write("���Ѿ���д��ע�ᵥ��\n");
    check_user();
 }
private void a(string arg, string register)
{
   register = "����     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    �����ǳ�     : "NOR);
   input_to((:b:),this_player(),register);
}
private void b(string arg, string register)
{
   register = "�ǳ�     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    ��ʵ����     : "NOR);
   input_to((:c:),this_player());
}
private void c(string arg, string register)
{
   register = "����     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    ��ϵ��ַ     : "NOR);
   input_to((:d:),this_player());
}
private void d(string arg, string register)
{
   register = "��ϵ��ַ     : "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    ������λ/ѧУ: "NOR);
   input_to((:e:),this_player());
}
private void e(string arg, string register)
{
   register = "������λ/ѧУ: "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    ��������: "NOR);
   input_to((:f:),this_player());
}
private void f(string arg, string register)
{
   register = "��������: "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"    ��ϵ�绰: "NOR);
   input_to((:g:),this_player());
}
private void g(string arg, string register)
{
   register = "��ϵ�绰: "+arg+"\n";
   this_player()->add_temp("register",register);
   write(HIW"\n\n\n\n\n\n���������Ƿ���ȷ(Y/N)��(Q)ȡ��ע�� [N]:"NOR);
   input_to((:y:),this_player());
}
private void y(string arg, string register) 
{
   string table;
   if(arg=="") {
   this_player()->delete_temp("register");
   register();
   return ;
   }
switch(arg[0]){
   case 'n':
           this_player()->delete_temp("register");
           register();
           return ;
   case 'y': 
           this_player()->set("register",1);
           table =  this_player()->query_temp("register");
           this_player()->delete_temp("register");
           write_file("/log/doc/register/"+this_player()->query("id"),table,1);
           write("������һ����ȷ��\n"); 
           check_user();
           return ;
   case 'q':
           this_player()->delete_temp("register");
           u_display();
           write(YEL"\r����������ѡ��:"NOR);
           input_to((:confirm_u_choice:),this_player());
           return ;
   default:
           this_player()->delete_temp("register");
           register();
           return ;
     }
  return ;
}
int check_nowait()
{
 if( this_player()->query_temp("help_a"))
 confirm_a_choice("");
 if( this_player()->query_temp("help_b"))
 confirm_b_choice("");
 if( this_player()->query_temp("help_c"))
 confirm_c_choice("");
 if( this_player()->query_temp("help_u"))
 confirm_u_choice("");
if( this_player()->query_temp("help_o"))
 confirm_o_choice("");
}
int check_user()
{
 if( this_player()->query_temp("help_a"))
 input_to("confirm_a_choice",this_player());
 if( this_player()->query_temp("help_b"))
 input_to("confirm_b_choice",this_player());
 if( this_player()->query_temp("help_c"))
 input_to("confirm_c_choice",this_player());
 if( this_player()->query_temp("help_u"))
 input_to("confirm_u_choice",this_player());
 if( this_player()->query_temp("help_o"))
 input_to("confirm_o_choice",this_player());
}
int start_help(string msg)
{
        helpmore("", explode(msg, "\n"), 0);
}
int main(object me, string arg)
{
        int i;
	string file, *search;
       	if( !arg ) {
                me->set_temp("help",1);
                m_display();
                write(YEL"�����ڵĴ��㣺"NOR);
                input_to((:confirm_main_choice:),this_player());
                return 1; 
        }
          	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("�����ָ����ڣ����ǲ�û����ϸ��˵���ļ���\n");
		return file->help(me);
	}
       if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}
	sscanf(arg, "%s()", arg);
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more( read_file(default_search[i] + arg) );
			return 1;
		}
  	  }
	return notify_fail("û��������������˵���ļ���\n");
	}

void view_main()
{
     object me;
     string name,select;
     me = this_player();
     select = me->query_temp("select");
     write(CLR"\n");
     if(select== "main") name = "�û�ָ��";
     else if( select== "intro") name = "��Ϸ�ſ�";
     else if( select== "depart") name = "���ɽ���";
     else if( select== "map") name = "����ָ��";
     else if( select== "user") name = "�����趨��";
     else if( select== "board") name = "��Ҫ������";
     write(HIY"����ѡ��"HIW"                     ��"+MUD_NAME+"��                  "HIY"ѡ��["+select+"]\n"NOR);     
     write("Ŀǰѡ��[ "+name+" ]\n");
     write(HIR"�������������������������������� ����� ��������������������������������\n"NOR);
     auto_load();
     write(HIR"������������������������������������������������������������������������\n"NOR);  
     write("\n");
}
void view_main_1()
{
     int i,ppl_cnt;
     object *usr;
     usr = users();
     ppl_cnt=0;
     for(i=0; i<sizeof(usr); i++)
       {
          ppl_cnt++;
       }
     write("\n");   
     write(YEL"_.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*```*-.__.-*\n"NOR);
     write("\n");     
     write(HIY"TIME:["HIC""+ctime(time())+""HIY"]    ONLINE/PLAYER:["HIC""+ppl_cnt+""HIY"]    USER:["HIC""+wizhood(this_player())+""HIY"]\n"NOR,);
     write("\n");
}
void a_display()
{
     view_main();
     write(HIW+intro+NOR);
     view_main_1();
}
void b_display()
{
     view_main();
     write(HIW+depart+NOR);
     view_main_1();
}
void c_display()
{
     view_main();
     write(HIW+map+NOR);
     view_main_1();
}
void o_display()
{
     write(CLR"\n");
     write(HIY"\n  ���   �����            ��   ��   ��   ��          ����Ա"NOR"\n\n");
     write(HIW+board+NOR);
     view_main_1();
}
void m_display()
 {
     this_player()->set_temp("select","main");
     view_main();
     write("                        "HIY"(��)"NOR"ntro  ����  ��Ϸ�ſ�  ��\n");
     write("                        "HIY"(��)"NOR"epart ����  ���ɽ���  ��\n");
     write("                        "HIY"(��)"NOR"ap    ����  ����ָ��  ��\n");
     write("                        "HIY"(��)"NOR"ser     �� �����趨�� ��\n");
     write("                        "HIY"(��)"NOR"board ���� ��Ҫ������ ��\n");
     write("                        "HIY"(��)"NOR"yz      �� ϵͳ�趨�� ��\n"); 
     write("                        "HIY"(��)"NOR"oodbye�� �ٱ𡾰������������������\n");
     view_main_1();
}
void u_display()
{
      view_main();
      write("                       "HIC"(��)"NOR"nfo        ��������\n");
      write("                       "HIC"(��)"NOR"ill        ��ȫ��ɱ�ֲ�\n");
      if (wizardp(this_player()))
      write("                       "HIC"(��)"NOR"loak       ������\n");
      write("                       "HIC"(��)"NOR"ockScreen  ����өĻ\n");
      write("                       "HIC"(��)"NOR"egister    ��д��ע�����뵥��\n");
      write("                       "HIC"(��)"NOR"ager       �л�������\n");
      write("                       "HIC"(��)"NOR"return     �������˵�\n");
      view_main_1();
}
int pager()
{
    object me;
    me = this_player();
    if(me->query_temp("call_on")) {
    write("�� Pager Ƶ��\n");
    me->delete_temp("call_on");
    }
   else{
   write("�ر� Pager Ƶ��\n");
   me->set_temp("call_on",1);
   }
  return 1;
}

void auto_load()
{
    if(random(10) > 5)
    wizlist();
    else if( random(20) >  10)
    message(); 
    else 
    message1();
}
int message1()
{
       object me;
      int i;
      me = this_player();
      i = me->query("MKS")+me->query("PKS");
      write(HIC"      "+me->name()+"��, ������Ѿ����������"+age_string((int)me->query("mud_age"))+"��!!\n");
      write(HIW"      �����ڱ���͵ķַ�������, ���Ѿ��ۻ���"+chinese_number(me->query("combat_exp"))+"�㾭��ֵ\n");
      write(HIW"      ������"+chinese_number(i)+"������\n");
      write(HIC"                    �����!! \n");
}
string age_string(int time)
{
        int month, day, hour, min, sec;

        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time % 30;
        month = time / 30;
        return (month?month + "��":"") + (day?day + "��":"") +
        (hour?hour + "Сʱ":"") + min + "��";
}
int message()
{
 write(HIR"   ��    �� �� ��  ����      ��     ��     ����   �����   ����\n"NOR);
 write(HIB" ������   ������    ������   ����     ������   ������     ��      ����\n"NOR);
 write(HIY"  ����    ��  ��   ��         �� ��    ����     �� ��   ��  ��    ������\n"NOR);
 write(HIC""+this_player()->name()+",ǧ�������̫��ඣ�ע��������塣������Ӥ֮��Ȼ����������֮������\n"NOR);
}
int wizlist()
{
        string *wizlist,*list,wiz_name,wiz_level,str,str1,str2,str3,str4;
        int i,s1,s2,s3,s4;
        str1="",str2="",str3="",str4="";
        s1=0;s2=0;s3=0;s4=0;

        list = sort_array(SECURITY_D->query_wizlist(),1);
        wizlist = explode(read_file(WIZLIST), "\n");
        for(i=0; i<sizeof(wizlist); i++)  {
        sscanf(wizlist[i], "%s %s", wiz_name, wiz_level);
                switch(wiz_level)
                {
                        case "(apprentice)":
                                str1 += (s1?"\t":"")+wiz_name;
                                s1++;
                                if(s1%6==0) str1 += "\n \t\t ";
                                break;
                        case "(wizard)":
                                str2 += (s2?"\t":"")+wiz_name;
                                s2++;
                                if(s2%6==0) str2 += "\n \t\t ";
                                break;
                        case "(arch)":
                                str3 += (s3?"\t":"")+wiz_name;
                                s3++;
                                if(s3%6==0) str3 += "\n \t\t ";
                                break;
                        case "(admin)":
                                str4 += (s4?"\t":"")+wiz_name;
                                s4++;
                                if(s4%6==0) str4 += "\n \t\t";
                                break;

                }
        }
        write(HIR"   �� ɢ �� ��: "NOR+str1+"\n");
        write(HIY"   �� �� �� ��: "NOR+str2+"\n");
        write(HIG"   �� �� �� ��: "NOR+str3+"\n");
        write(HIW"   �� �� �� ��: "NOR+str4+"\n");
}
private void confirm_a_choice(string arg)
{
    this_player()->set_temp("help_a",1);
   if(arg=="") {
 a_display();
 write(YEL "\r�������������ѡ��:"NOR);
 input_to((:confirm_a_choice:),this_player());
 return ; }
 switch(arg){
    case "1":
              start_help(read_file("/doc/help/intro"));
              return ;
    case "2":
             start_help(read_file("/doc/help/commands"));
             return ;
    case "3":
             start_help(read_file("/doc/help/newbie"));
             return ;
    case "4":
             start_help(read_file("/doc/help/rules"));
             return ;
    case "5": 
             start_help(read_file("/doc/help/settings"));
             return ;
    case "6":
             start_help(read_file("/doc/help/setup"));
             return ;
    case "7":
             start_help(read_file("/doc/help/wizrules"));
             return ;
    case "8":
             start_help(read_file("/doc/help/neima"));
             return ;
    case "b":
             this_player()->delete_temp("help_a");
             m_display();
             write(YEL "\r����������ѡ��:"NOR);
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
           a_display();
           write(YEL"\r����������ѡ��:"NOR);
           input_to((:confirm_a_choice:),this_player());
           return ;
        }
  return;
}
private void confirm_b_choice(string arg)
{
   this_player()->set_temp("help_b",1);
   if(arg=="") {
       b_display();
       write(YEL "\r�������������ѡ��:"NOR);
       input_to((:confirm_b_choice:),this_player());
       return ; }

 switch(arg){
    case "1":
              start_help(read_file("/doc/help/shaolin"));
              return ;
    case "2": 
              start_help(read_file("/doc/help/wudang"));
              return ;    
    case "3":
              start_help(read_file("/doc/help/huashan"));
             return ;
    case "4":
             start_help(read_file("/doc/help/emei"));
             return ;
    case "5":
             start_help(read_file("/doc/help/taohua"));
             return ; 
    case "8":
             start_help(read_file("/doc/help/gaibang"));
             return ; 
    case "6":
             start_help(read_file("/doc/help/xingxiu"));
             return ; 
    case "7":
             start_help(read_file("/doc/help/kunlun"));
             return ;
    case "9":
             start_help(read_file("/doc/help/gumu"));
             return ;
    case "12":
             start_help(read_file("/doc/help/mingjiao"));
             return ; 
    case "10":
             start_help(read_file("/doc/help/tianlongsi"));
             return ;
    case "11":
             start_help(read_file("/doc/help/yipin"));
             return ;
    case "b":
             this_player()->delete_temp("help_b");
             m_display();
             write(YEL "\r�������������ѡ��:"NOR);
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
           b_display();
           write(YEL"\r����������ѡ��:"NOR);
           input_to((:confirm_b_choice:),this_player());
           return ;
        }
  return;
}
private void confirm_c_choice(string arg)
{
 this_player()->set_temp("help_c",1);
 if(arg=="") {
     c_display();
     write(YEL "\r�������������ѡ��:"NOR);
     input_to((:confirm_c_choice:),this_player());
     return; }
 switch(arg) {
    case "1":
             start_help(read_file("/doc/help/maps/huashan-map"));
             return ;
    case "2":
             start_help(read_file("/doc/help/maps/taishan-map"));
             return ;
    case "3":
             start_help(read_file("/doc/help/maps/yangzhou-map"));
             return ;
    case "4":
             start_help(read_file("/doc/help/maps/jiaxing-map"));
             return ;
    case "5":
             start_help(read_file("/doc/help/maps/beijiang-map"));
             return ;
    case "6":
             start_help(read_file("/doc/help/maps/xingxiu-map"));
             return ;
    case "7":
             start_help(read_file("/doc/help/maps/changan-map"));
             return ;
    case "8":
             start_help(read_file("/doc/help/maps/xiangyang-map"));
             return ;
    case "9":
             start_help(read_file("/doc/help/maps/shaolin-map"));
             return ;
    case "10":
             start_help(read_file("/doc/help/maps/chengdu-map"));
             return ;
    case "11":
             start_help(read_file("/doc/help/maps/kunlun-map"));
             return ;
    case "12":
             start_help(read_file("/doc/help/maps/emei-map"));
             return ;
    case "13":
             start_help(read_file("/doc/help/maps/huashancun-map"));
             return ;
    case "14":
             start_help(read_file("/doc/help/maps/chengdu-map"));
             return ;
    case "15":
             start_help(read_file("/doc/help/maps/quanzhen-map"));
             return ;
    case "16":
             start_help(read_file("/doc/help/maps/mingjiao-map"));
             return ;
    case "17":
             start_help(read_file("/doc/help/maps/wangfu-map"));
             return ;
    case "18":
             start_help(read_file("/doc/help/maps/tianlongsi-map"));
             return ;
    case "19":
             start_help(read_file("/doc/help/maps/dali-map"));
             return ;
    case "20":
             start_help(read_file("/doc/help/maps/suzhou-map"));
             return ;
    case "21":
             start_help(read_file("/doc/help/maps/yanziwu-map"));
             return ;
    case "22":
             start_help(read_file("/doc/help/maps/hangzhou-map"));
             return ;
    case "23":
             start_help(read_file("/doc/help/maps/fuzhou-map"));
             return ;
    case "b":
             m_display();
             write(YEL "\r����������ѡ��:"NOR);
             this_player()->delete_temp("help_c");
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
           c_display();
           write(YEL"\r����������ѡ��:"NOR);
           input_to((:confirm_c_choice:),this_player());
           return ;
        }
  return;
}
int lock()
{
    object me,ob;
    me = this_player();
    ob = me->query_temp("link_ob"); 
    write(HIW"�� ���������룬�Խ��өĻ������"NOR);
    input_to("get_old_pass", 1, ob);
    return 1;
}
void get_old_pass(string pass, object ob)
{
        string old_pass;
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
        lock();
        return ; }
        u_display();
        write(YEL"\r����������ѡ��:"NOR);
        input_to((:confirm_u_choice:),this_player());
        return ;
} 
         
int cloak()
{
   object me;
   me = this_player();
   if(!wizardp(me))
    {
           u_display();
           write(YEL"\r����������ѡ��:"NOR);
           input_to((:confirm_u_choice:),this_player());
           return 1;
   } 
   if(me->query("env/invisibility")) 
   {
    write("��Ҫ���ֽ���...\n");
    me->delete("env/invisibility");
    }
   else {
    write("�����������������ˡ�\n");
    me->set("env/invisibility",5);
   }
  return 1;
}
private void confirm_u_choice(string arg)
{

 this_player()->set_temp("help_u",1);
 if(arg=="") {
     u_display();
     write(YEL "\r�������������ѡ��:"NOR);
     input_to((:confirm_u_choice:),this_player());
     return ; }

 switch(arg[0]){
    case 'r':
            register();
            return ;
    case 'p':
            pager();
            check_user();
             return ;
    case 'c':
            cloak();
            check_user();
            return ;
    case 'l':
            lock();
            return ;
    case 'f':
    case 'g':
    case 'h':
    case 'g':
             m_display();
             write(YEL "\r����������ѡ��:"NOR);
             this_player()->delete_temp("help_u");
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
           u_display();
           write(YEL"\r����������ѡ��:"NOR);
           input_to((:confirm_u_choice:),this_player());
           return ;
        }
  return;
}
private void confirm_o_choice(string arg)
{
 this_player()->set_temp("help_o",1);
 if(arg=="") {
      o_display();
      write(YEL "\r�������������ѡ��:"NOR);
      input_to((:confirm_o_choice:),this_player());
      return ; }
 switch(arg){
    case "1":
             start_help(read_file("/doc/help/boards/applywiz"));
             return ;
    case "2":
             start_help(read_file("/doc/help/boards/gab"));
             return ;
    case "3":
             start_help(read_file("/doc/help/boards/pet"));
             return ;
    case "4":
             start_help(read_file("/doc/help/boards/checkip"));
             return ;
    case "5":
             start_help(read_file("/doc/help/boards/quest"));
             return ;
    case "6":
             start_help(read_file("/doc/help/boards/transport"));
             return ;
    case "7":
             start_help(read_file("/doc/help/boards/passwd"));
             return ;
    case "8":
             start_help(read_file("/doc/help/boards/sboard"));
             return ;
    case "9":
             start_help(read_file("/doc/help/boards/pig_cmds"));
             return ;
    case "10":
             start_help(read_file("/doc/help/boards/crash"));
             return ;
    case "11":
             start_help(read_file("/doc/help/boards/force"));
             return ;
    case "b":
             m_display();
             write(YEL "\r����������ѡ��:"NOR);
             this_player()->delete_temp("help_o");
             input_to((:confirm_main_choice:),this_player());
             return ;
    default:
             o_display();
             write(YEL"\r����������ѡ��:"NOR);
             input_to((:confirm_o_choice:),this_player());
             return ;
        }
  return;
}
private void confirm_main_choice(string arg)
{
  if(arg=="") {
       m_display();
       write(YEL "\r�������������ѡ��:"NOR);
       input_to((:confirm_main_choice:),this_player());
       return ; }
 switch(arg[0]){
    case 'g':
             this_player()->delete_temp("select");
             this_player()->delete_temp("help");
             return;
    case '6':
             this_player()->delete_temp("select");
             return;
    case 'u':
             this_player()->set_temp("select","user");
             u_display();
             write(YEL"\r����������ѡ��:"NOR);
             input_to((:confirm_u_choice:),this_player());
             return ;             
    case 'b':
             this_player()->set_temp("select","board");
             o_display();
             write(YEL"\r����������ѡ��:"NOR);
             input_to((:confirm_o_choice:),this_player());
             return ;
    case 'i':
             this_player()->set_temp("select","intro");
             a_display();
             write(YEL"\r����������ѡ��:"NOR);
             input_to((:confirm_a_choice:),this_player());
             return ;
    case 'd':
             this_player()->set_temp("select","depart");
             b_display();
             write(YEL"\r����������ѡ��:"NOR);
             input_to((:confirm_b_choice:),this_player());
             return ;
    case 'm':
             this_player()->set_temp("select","map");
             c_display();
             write(YEL"\r����������ѡ��:"NOR);
             input_to((:confirm_c_choice:),this_player());
             return ;    
     default:
           m_display();
           write(YEL"\r����������ѡ��:"NOR);
           input_to((:confirm_main_choice:),this_player());
           return;
        }
  return;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : help

�����ô���������ϸ�˽Ȿ��Ϸ��
HELP
    );
    return 1;
}