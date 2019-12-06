// logind.c
// modified by Eatdami@MX (10/13/2000)

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <mudlib.h>

#define MAXONLINE       "/adm/etc/maxonline"
#define FileName        "/adm/etc/counter"
#define JYQXZINFO       "/adm/etc/jyqxzinfo"

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
int mad_lock = 0;
int p_num,max_online;
string jyqxz_info,welcome;

string *banned_name = ({
        "��", "��", "��", "��", "��", "��ʦ", "��ʦ����Ա", "����Ա", "����"
        "ʱ��","����","����","��","ϵͳ", "����", "ϵͳ����",
});

string *banned_id= ({
        "chat", "new", "jy", "rumor", "tell", "none", "reboot","liling",
        "fy","es", "shutdown","core", "fymud","mud", "fuck","fuckyou","fuckfuck",
        "dick",  "shit","cao","cunt","slut",
        "player", "immortal", "apprentice", "wizard", "arch", "admin",
        "root", "shutdown", "super", "superuser",
});

//string welcome_big5="�w��Ө�u���e�s�L�ǡv�A�п�J��΢�...\n��ӭ��������ӹȺ���������밴�س�����...";
string welcome_big5=HIW"Welcome to JYQX II��Select GB(Enter) or BIG5(B)"NOR;

string *start_room = ({
        "/d/xingxiu/beijiang",
        "/d/quanzhou/tieqiang",
        "/d/city/wumiao",
        "/d/city2/kedian",
        "/d/city2/wenmiao",
});

private void logon_main(string no_use,object ob);
void get_id(string arg, object ob);
void confirm_id(string yn, object ob);
object make_body(object ob);
void init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
int do_counter();
int get_wizlock();

void random_gift(mapping my)
{
        int i;
        int tmpstr, tmpint, tmpcon, tmpdex;
        tmpstr = tmpint = tmpcon = tmpdex = 10;

        for (i = 0; i < 40; i++) {
                switch (random(4)) {
                case 0: tmpstr++; break;
                case 1: tmpint++; break;
                case 2: tmpcon++; break;
                case 3: tmpdex++; break;
                }
        }
        if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
        if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
        // next 2 are randomly selected
        my["kar"] = 10 + random(21);
        my["per"] = 10 + random(21);
}

void create()
{
        string str;

        seteuid(getuid());
        set("channel_id", "���߾���");
        str = read_file(MAXONLINE);
        if( !str || !sscanf(str,"%d",max_online) )
                max_online = 0;
        welcome = read_file(WELCOME);
        jyqxz_info = read_file(JYQXZINFO) +"\n";
}

void logon(object ob)
{
        write(welcome);
        write(welcome_big5);
        input_to( (: logon_main :),ob);
}

private void logon_main(string arg,object ob)
{
        object *usr;
        int i, wiz_cnt, ppl_cnt,ip_cnt,ban_cnt,login_cnt;
        string str;
        int encode;

        arg = lower_case(arg);
        if(!arg || arg[0..0] != "b")
                encode=0;
        else 
		encode=1;
        ob->set_encoding(encode);
        write("\n");

        if( mad_lock == 1 ) {
                write("����ʱ���Ѿ�����ˣ����ܽ��룡�� \n");
                destruct(ob);
                return;
        }

        if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
                write("��ĵ�ַ�ڱ� MUD ���ܻ�ӭ��\n");
                destruct(ob);
                return;
        }
        write(jyqxz_info);
        write(RED + CHINESE_MUD_NAME + " " + YEL + base_version() + RED" -- " + YEL + driver_version() + "\n"NOR);
        UPTIME_CMD->main();

        usr = users();
        wiz_cnt = 0;
        ppl_cnt = 0;
        ip_cnt  = 0;
        ban_cnt = 0; 
        login_cnt = 0;
        str=query_ip_name(ob);
        for(i=0; i<sizeof(usr); i++) {
                if (str==query_ip_name(usr[i]))
                        ip_cnt++;
                if( str==query_ip_name(usr[i]) && !environment(usr[i]) )
                        ban_cnt++;
                if( !environment(usr[i]) )
                        login_cnt++;
                else if( wizardp(usr[i]) )
                        wiz_cnt++;
                else
                        ppl_cnt++;
        }
        if( (ppl_cnt + wiz_cnt) > max_online ) {
                max_online = ppl_cnt + wiz_cnt;
                write_file(MAXONLINE,sprintf("%d",max_online),1);
        }

        do_counter();
        printf(RED"�����ڴ�"YEL"%s"RED"���߽��롣%s\nĿǰ����"YEL"%s"RED"λ��ʦ��"YEL"%s"RED"λ������ߣ�����"YEL"%s"RED"λ�û��ڳ������ӡ�\n\n"NOR,
        str,ip_cnt-1?"�������ַ�ϣ�����"+YEL+chinese_number(ip_cnt-1)+RED+"λ������ҡ�":"",
        chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );
        p_num=0;  //counter of Player's login times.
        write(HIW"����Ӣ�����֣�"NOR);
        input_to( (: get_id :), ob );
}

void get_id(string arg, object ob)
{
        object ppl;
        object *usr;
        int i, wiz_cnt;

        arg = lower_case(arg);
        if( !check_legal_id(arg)) {
                write(HIW"����Ӣ�����֣�"NOR);
                input_to("get_id", ob);
                return;
        }

#ifdef MAX_USERS

        usr = users();
        wiz_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( wizardp(usr[i]) ) wiz_cnt++;
        }
        if( (string)SECURITY_D->get_status(arg)=="(player)"
         && (sizeof(usr) - wiz_cnt) >= MAX_USERS ) {
                ppl = find_body(arg);
                // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write("�Բ���" + MUD_NAME + "��ʹ�����Ѿ�̫���ˣ������������\n");
                        destruct(ob);
                        return;
                }
        }
#endif

        if( query_wiz_level(SECURITY_D->get_status(arg)) < wiz_lock_level ) {
                write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + WIZ_LOCK_LEVEL
                        + " ���ϵ��˲������ߡ�\n");
                destruct(ob);
                return;
        }
        if( (string)ob->set("id", arg) != arg ) {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
        }

        if( arg=="guest" ) {
                // If guest, let them create the character.
                confirm_id("Yes", ob);
                return;
        } else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 )
{
                if( ob->restore() ) {
                        write(HIW"���������룺"NOR);
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("�������ﴢ�浲����һЩ���⣬������ guest ����֪ͨ��ʦ������\n");
                destruct(ob);
                return;
        }

        write("ʹ�� " + (string)ob->query("id") + " ������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
        input_to("confirm_id", ob);
}
void get_passwd(string pass, object ob)
{
        string my_pass;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass ) {
        if(p_num<2) {
        p_num=p_num+1;
        write(HBRED "��������"+chinese_number(p_num)+"�������������" NOR);
/*
        write(MAG"\n\n��������������Ӣ�����֣�"NOR);
        input_to("get_id", ob,1);
*/
        write(HIW"\n\n�����������������룺");
	input_to("get_passwd", 1, ob);
        return;
        }
        write(HIR"�Բ������Ѿ�����������������������������\n");
                //write("�������\n");
                destruct(ob);
                return;
        }

        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user) {
                if( user->query_temp("netdead") ) {
                        reconnect(ob, user);
                        return;
                }
                write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( objectp(user = make_body(ob)) ) {
                if( user->restore() ) {
                        log_file( "USAGE", sprintf("%s loggined from %s (%s)\n", user->query("name"),
                                query_ip_name(ob), ctime(time()) ) );
                        enter_world(ob, user);
                        return;
                } else {
                        destruct(user);
                }
        }
        write("�������´���������\n");
        confirm_id("y", ob);
}

void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("�ðɣ���ӭ�´�������\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
                        + " )����ȡ���������Ƶ����\n");
                log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", user->query("name"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if( old_link ) {
		user->set_encoding(ob->query_encoding());
                exec(old_link, user);
                destruct(old_link);
        }

        reconnect(ob, user);
}

void confirm_id(string yn, object ob)
{
        if( yn=="" ) {
                write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
                input_to("confirm_id", ob);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write(MAG"�ðɣ���ô��������������Ӣ�����֣�"NOR);
                input_to("get_id", ob);
                return;
        }
        write( @TEXT

���������ĸ��մ���������������ִ��������������Ժ��ܸ��ģ�
����������������Ź۵���������ɾ�����������벻Ҫѡ���ӹС˵��
��������������

(��������֮�⣬�� mud ������ȡ�ºš���Ƶ���ƣ�����֣�ؽ�����
 ȡһ���Ƚ������ֵ��������֡�)
TEXT
        );
        write(HIM"�����������֣�"NOR);
        input_to("get_name", ob);
}

void get_name(string arg, object ob)
{
        if( !check_legal_name(arg) ) {
                write("�����������֣�");
                input_to("get_name", ob);
                return;
        }
        printf("%O\n", ob);
        ob->set("name", arg);
        write("���趨�������룺");
        input_to("new_password", 1, ob);
}

void new_password(string pass, object ob)
{
        write("\n");
        if( strlen(pass)<5 ) {
                write("����ĳ�������Ҫ����ַ����������������룺");
                input_to("new_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write("��������һ���������룬��ȷ����û�Ǵ���");
        input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
        mapping my;
        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("��������������벢��һ�����������趨һ�����룺");
                input_to("new_password", 1, ob);
                return;
        }

        write(@TEXT
һ��������츳��������������ϰ������ϢϢ��ء���ӹȺ�����е����������
���������츳��

        ������Ӱ�칥���������������Ĵ�С��
        ���ԣ�Ӱ��ѧϰ�书�ؼ����ٶȼ�����ʦ����������
        ���ǣ�Ӱ�������ָ����ٶȼ������������ӵ�������
        ������Ӱ���������ܵ�������

TEXT);
        my = ([]);
        write("���Ƿ����Զ��츳(y/n)��");
	input_to("get_choice",ob,my);
}

//added by long, 1999.7.6
void get_choice(string yn, object ob, mapping my)
{
        if (yn[0] != 'y' && yn[0] != 'Y') {
                write("\n������ϵͳΪ���趨�츳��\n");
		random_gift(my);
		printf("\n����[%d]�� ����[%d]�� ����[%d]�� ����[%d]\n",
			my["str"], my["int"], my["con"], my["dex"]);
		write("��������һ���츳��(y/n)");
                input_to("get_gift", ob, my);
        }
        if (yn[0] == 'y' || yn[0] == 'Y') {
        printf("\n��������������˳���Զ��츳��\n�����츳�ܵ���Ϊ80������������"+HIC"��������"NOR+"����(10-30)��");
        input_to("get_tf1", ob, my);
	}
}
void get_gift(string yn, object ob, mapping my)
{
        if (yn[0] != 'y' && yn[0] != 'Y') {
                random_gift(my);
                printf("\n����[%d]�� ����[%d]�� ����[%d]�� ����[%d]\n",
                      my["str"], my["int"], my["con"], my["dex"]);
		write("��ͬ����һ���츳��(y/n)��");
                input_to("get_gift", ob, my);
        }
        if (yn[0] == 'y' || yn[0] == 'Y') {
                input_to("get_email", ob, my);
                write("\n���ĵ����ʼ���ַ��");
        }
}

void get_tf1(string gift, object ob, mapping my)
{
	int tf1, rest;
        if(sscanf(gift,"%d",tf1)!=1 || tf1 > 30 || tf1 <10) {
                write("����ֵ������"+HIR"10-30"NOR+"֮�䣡\n");
		printf("�����츳�ܵ���Ϊ80������������"+HIC"��������"NOR+"����(10-30)��");
                input_to("get_tf1",ob,my);
        }
	else {
	        my["str"]=tf1;
		rest=80-tf1;
		printf("\n�����츳��������%d�㣬����������"+HIC"�����ԡ�"NOR+"����(10-30)��", rest);
		input_to("get_tf2",ob,my);
		}
}

void get_tf2(string gift, object ob, mapping my)
{
	int tf2, rest, rest1, rest2;
        if(sscanf(gift,"%d",tf2)!=1 || tf2 > 30 || tf2 <10) {
                write("����ֵ������"+HIR"10-30"NOR+"֮�䣡\n");
		printf("\n�����츳��������%d�㣬����������"+HIC"�����ԡ�"NOR+"����(10-30)��", 80-my["str"]);
                input_to("get_tf2",ob,my);
        }
	else {
	        my["int"]=tf2;
		rest=80-my["str"]-my["int"];
		if ( rest < 40 ) {
			rest1=rest-10;
			rest2=10;
		} else {
			rest1=30;
			rest2=rest-30;
			}
	        printf("\n�����츳��������%d�㣬����������"+HIC"�����ǡ�"NOR+"����(%d-%d)��", rest, rest2, rest1);
		input_to("get_tf3",ob,my);
		}
}

void get_tf3(string gift, object ob, mapping my)
{
	int tf3, rest1, rest2;
	int rest=80-my["str"]-my["int"];
	if ( rest < 40 ) {
		rest1=rest-10;
		rest2=10;
	} else {
		rest1=30;
		rest2=rest-30;
		}
        if(sscanf(gift,"%d",tf3)!=1 || tf3 > rest1 || tf3 <rest2) {
		printf("����ֵ������"+HIR"%d-%d"NOR+"֮�䣡\n", rest2, rest1);
	        printf("�����츳��������%d�㣬����������"+HIC"�����ǡ�"NOR+"����(%d-%d)��", rest, rest2, rest1);
                input_to("get_tf3",ob,my);
        }
	else {
	        my["con"]=tf3;
		my["dex"]=80-my["str"]-my["int"]-my["con"];
		if( my["dex"] < 10 || my["dex"] > 30 )
		{
			write("�����趨���ԣ��������趨��\n");
			printf("�����츳�ܵ���Ϊ80������������"+HIC"��������"NOR+"����(10-30)��");
                	input_to("get_tf1",ob,my);
        	}
		else {
	                printf("\n����[%d]�� ����[%d]�� ����[%d]�� ����[%d]\n",
        	              my["str"], my["int"], my["con"], my["dex"]);
		write("��������һ���츳��(y/n)");
	        input_to("get_choice2", ob, my);
		}
	}
}
void get_choice2(string yn, object ob, mapping my)
{
        if (yn[0] != 'y' && yn[0] != 'Y') {
		write("�������趨�����츳��\n�����츳�ܵ���Ϊ80������������"+HIC"��������"NOR+"����(10-30)��");
               	input_to("get_tf1",ob,my);
        }
        if (yn[0] == 'y' || yn[0] == 'Y') {
                write("\n���ĵ����ʼ���ַ��");
                input_to("get_email", ob, my);
        }
}

void get_email(string email, object ob, mapping my)
{
        object user;
        string id,address;

        write("\n");
        if (email == "" || strsrch(email, "@") == -1 || sscanf(email,"%s@%s",id,address)!=2||strsrch(address,".")==-1)
        {
                write("�����ʼ���ַ��Ҫ�� id@address �ĸ�ʽ��\n");
                write("���ĵ����ʼ���ַ��");
                input_to("get_email", ob, my);
                return;
        }
        ob->set("email", email);
        ob->set("registered", 1);
        // If you want do race stuff, ask player to choose one here, then you can
        // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
                return;
        user->set("str", my["str"]);
        user->set("dex", my["dex"]);
        user->set("con", my["con"]);
        user->set("int", my["int"]);
        ob->set("registered", 1);
        user->set("registered", 1);

        write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
        input_to("get_gender", ob, user);
}

void get_gender(string gender, object ob, object user)
{
        write("\n");
        if( gender=="" ) {
                write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "����");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "Ů��" );
        else {
                write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
                query_ip_name(ob), ctime(time()) ) );
        init_new_player(user);
        enter_world(ob, user);
        write("\n");
}

object make_body(object ob)
{
        string err;
        object user;

        user = new(ob->query("body"));
        if(!user) {
                write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

void init_new_player(object user)
{
        user->set("title", "��ͨ����");
        user->set("birthday", time() );
        user->set("potential", 500);
        user->set("channels", ({ "chat", "rumor" }) );
// Added by Hop, 97.07.09
        if(user->query("gender") == "Ů��")
        {
                user->set_temp("new_lady", 1);
                user->set("combat_exp",50);
        }
                user->add("combat_exp",3000);
}


varargs void enter_world(object ob, object user, int silent)
{
        object cloth, shoe, mailbox,weapon, money,magic,lottery;
        string startroom,weapon_type,file,name,id,number,time;
        string* lot_list;
        string* sname;
        object login_ob;
        int i = random(sizeof(start_room));
        int turn;
	mapping skl;

        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        user->set("registered", ob->query("registered"));
	user->set_encoding(ob->query_encoding());
        exec(user, ob);

        write("\nĿǰȨ�ޣ�" + wizhood(user) + "\n");

        user->setup();
        if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
                user->set("food", user->max_food_capacity());
                user->set("water", user->max_water_capacity());
        }

        // In case of new player, we save them here right aftre setup
        // compeleted.
        user->save();
        ob->save();
          user->set("last_save_time",time());// autosave requires,add by long.
        if( (time() - (int)user->query("prison/start_time"))
         < ((int)user->query("prison/release_time")*60) ) {
                write("�����ܴ����У��޷����߽��롣\n");
                destruct(user);
                return;
        } // add by Byp@MX


        if(user->query_temp("new_lady"))
        {
                money = new(SILVER_OB);
                money->set_amount(50);
                money->move(user);
                user->delete_temp("new_lady");
        }
        if(user->query("age")<18)
        {
               magic = new("/d/city2/obj/magic");
               magic->move(user);
        }

        mailbox = new("clone/misc/mailbox");
        mailbox->move(user);
// End of modification

        if(user->query("sleeped"))
                call_out("del_sleeped", 179, user);

        if (wizhood(user) == "(player)")
        {
                if (user->query("class")=="bonze")
                {
                        if (user->query("gender")=="Ů��")
                        {
                                cloth = new("/clone/cloth/ni-cloth.c");
                                shoe = new("/clone/cloth/ni-xie.c");
                        }
                        else
                        {
                                cloth = new("/clone/cloth/seng-cloth.c");
                                shoe = new("/clone/cloth/seng-xie.c");
                        }
                }
                else
                {
                        if (user->query("class")=="taoist")
                        {
                                if ( user->query("gender")=="Ů��")
                                {
                                        cloth = new("/clone/cloth/daogu-cloth.c");
                                        shoe = new("/clone/cloth/dao-xie.c");
                                }
                                else
                                {
                                        cloth = new("/clone/cloth/dao-cloth.c");
                                        shoe = new("/clone/cloth/dao-xie.c");
                                }
                        }
                        else
                        {
                                if ( user->query("gender")=="Ů��")
                                {
                                        shoe = new("/clone/cloth/female-shoe.c");
                                        switch (random(5))
                                        {
                                                case 1:
                                        cloth = new("/clone/cloth/female1-cloth.c");
                                                break;
                                                case 2:
                                        cloth = new("/clone/cloth/female2-cloth.c");
                                                break;
                                                case 3:
                                        cloth = new("/clone/cloth/female3-cloth.c");
                                                break;
                                                case 4:
                                        cloth = new("/clone/cloth/female4-cloth.c");
                                                break;
                                                default:
                                        cloth = new("/clone/cloth/female5-cloth.c");
                                        }
                                }
                                else
                                {
                                        shoe = new("/clone/cloth/male-shoe.c");
                                        switch (random(4))
                                        {
                                                case 1:
                                        cloth = new("/clone/cloth/male1-cloth.c");
                                                break;
                                                case 2:
                                        cloth = new("/clone/cloth/male2-cloth.c");
                                                break;
                                                case 3:
                                        cloth = new("/clone/cloth/male3-cloth.c");
                                                break;
                                                default:
                                        cloth = new("/clone/cloth/male4-cloth.c");
                                        }
                                }
                        }
                }
                cloth->move(user);
                cloth->wear();
                shoe->move(user);
                shoe->wear();
        }
        else {

                cloth = new("/d/city2/obj/jinduan");
		shoe = new("/clone/cloth/dao-xie");

                cloth->move(user);
		shoe->move(user);

                cloth->wear();
		shoe->wear();

        }


// Give user his weapon
// Modified by Mccc at 1997.07.04
        if ( user->query("weapon/make") ) {
                weapon_type = user->query("weapon/type");
                switch(weapon_type){
                        case "��":
                                weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
                                weapon->move(user);
                                break;
                        case "��":
                                weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
                                weapon->move(user);
                                break;
                        case "��":
                                weapon = new("/d/npc/m_weapon/weapon/m_club",1);
                                weapon->move(user);
                                break;
                        case "��":
                                weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
                                weapon->move(user);
                                break;
                        case "��":
                                weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
                                weapon->move(user);
                                break;
                                weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
                                weapon->move(user);
                                break;
                }
        }
//add by wind for lottery
    if ( user->query("lotteriesold") ) {
	file=read_file("/log/LOTTERYOLD");
	if(file){
	lot_list=explode(file,"\n");
        for(i=0;i<sizeof(lot_list);i++) {
        if(sscanf(lot_list[i], "%s(%s) buy ��%d�ڲ�Ʊ %s at %s", name,id,turn,number,time) == 5 )
          {
          if(user->query("id")==id&&number!="aaaaaaa")
             {
		lottery=new("/u/wind/lotteries.c");
		lottery->set("number",number);
		lottery->set("master",name);
		lottery->set("time",time);
		lottery->set("turn",turn);
		lottery->move(user);
             }
          }
         }  
       }
       }
    if ( user->query("lotteries") ) {
	file=read_file("/log/LOTTERY");
	if(file){
	lot_list=explode(file,"\n");
        for(i=0;i<sizeof(lot_list);i++) {
        if(sscanf(lot_list[i], "%s(%s) buy ��%d�ڲ�Ʊ %s at %s", name,id,turn,number,time) == 5 )
          {
          if(user->query("id")==id&&number!="aaaaaaa")
             {
		lottery=new("/u/wind/lotteries.c");
		lottery->set("number",number);
		lottery->set("master",name);
		lottery->set("time",time);
		lottery->set("turn",turn);
		lottery->move(user);
             }
          }
         }  
       }
       }

       
        if( !silent ) {
                write(read_file(MOTD));

                printf("\n�� Enter ������......");
                input_to("",1);

                if( ob->query("new_mail") ) {
                        write( sprintf(HIG + "\n���� %d �����ţ��쿴�������ɣ�\n\n" + NOR,ob->query("new_mail")));
                        ob->set("new_mail", 0);
                }
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;

                else if( !stringp(startroom = user->query("startroom")) )
                        startroom = start_room[i];

                if( !catch(load_object(startroom)) )
                        user->move(startroom);
                else {
                        user->move(start_room[i]);
                        startroom = start_room[i];
                        user->set("startroom", start_room[i]);
                }
                tell_room(startroom, user->query("name") + "���߽���������硣\n",
                        ({user}));
        }
        login_ob=new(LOGIN_OB);
        login_ob->set("id",user->query("id"));
        login_ob->restore();
        write("���ϴ������Ǵ�" + HIR +login_ob->query("last_from") + NOR + " on " + HIR +ctime(login_ob->query("last_on"))+ NOR + "\n");
        destruct(login_ob);

//changed by long
        CHANNEL_D->do_channel( this_object(), "sys",
        sprintf("%s(%s)��%s���߽��룬�����"+reclaim_objects() + " ��������\n", user->name(), user->query("id"),
             query_ip_name(user)) );
        UPDATE_D->check_user(user);
        STATUS_D->compare_status(user);
//add by wind
        user->set_temp("temp_exp",user->query("combat_exp"));
        user->set_temp("temp_time",time());
        skl = user->query_skills();
        if( skl )
        sname = keys(skl);
        if(!user->query_temp("new_lady"))
      {
         for(i=0; i<sizeof(skl); i++)
        {
         if (skl[sname[i]] >= 180)
         {
         if( user->query("combat_exp") < 1000000 || user->query("age") < 20)
         write_file("/log/static/maybebug",sprintf("%s on %s(%s)\n",user->short(),ctime(time()),user->query("id"))); 
         break;
                }
        }
     }
        if( ob->query("id") != user->query("id") )
        {
           destruct(ob);
           destruct(user);
           return ;
        }

}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
	user->set_encoding(ob->query_encoding());
        exec(user, ob);

        user->reconnect();
        if( !silent ) {
                tell_room(environment(user), user->query("name") + "�������߻ص�
������硣\n",
                ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)��%s�������߽��롣", user->query("name"), user->query("id"), query_ip_name(user)) );
        UPDATE_D->check_user(user);
        STATUS_D->check_user(user);
}

int check_legal_id(string id)
{
        int i;

        i = strlen(id);

        if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
                write(HIR"�Բ������Ӣ�����ֱ����� 3 �� 12 ��Ӣ����ĸ��\n"NOR);
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write(HIR"�Բ������Ӣ������ֻ����Ӣ����ĸ��\n"NOR);
                        return 0;
                }
        if( member_array(id, banned_id)!=-1 ) {
                write(HIR"�Բ�������Ӣ�����ֻ���������˵����š�\n"NOR);
                return 0;
        }

        return 1;
}

int check_legal_name(string name)
{
        int i;

        i = strlen(name);

        if( (strlen(name) < 2) || (strlen(name) > 10 ) ) {
                write("�Բ�������������ֱ����� 1 �� 5 �������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ��������á����ġ�ȡ���֡�\n");
                        return 0;
                }
        }
        if( member_array(name, banned_name)!=-1 ) {
                write("�Բ����������ֻ���������˵����š�\n");
                return 0;
        }
        return 1;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];

        return 0;
}

int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
}

int get_wizlock() { return wiz_lock_level; }

int set_madlock(int setmark)
{
        if( wiz_level(this_player(1)) < wiz_level("(arch)") )
                return 0;
        if( setmark == 1 ) mad_lock = 1;
        else mad_lock = 0;
        return 1;
}

int get_madlock()
{
        return mad_lock;
}
int do_counter()
{
        int number;
        string file;
        file = read_file(FileName);
        sscanf(file,"%d",number);
        number++;
        file=sprintf("%d",number);
        write_file(FileName,file,1);
        printf(RED"�Զ���������ʮ����������"+YEL+chinese_number(number-1)+RED"�������ߣ��������"YEL+chinese_number(max_online)+RED"�ˡ�\n"NOR);

}

void del_sleeped(object me)
{
        if (objectp(me) &&  me->query("sleeped"))
                me->set("sleeped",0);
}
