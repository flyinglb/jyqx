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
        "你", "我", "他", "她", "它", "巫师", "巫师测试员", "测试员", "测试"
        "时空","李凌","风云","龙","系统", "核心", "系统核心",
});

string *banned_id= ({
        "chat", "new", "jy", "rumor", "tell", "none", "reboot","liling",
        "fy","es", "shutdown","core", "fymud","mud", "fuck","fuckyou","fuckfuck",
        "dick",  "shit","cao","cunt","slut",
        "player", "immortal", "apprentice", "wizard", "arch", "admin",
        "root", "shutdown", "super", "superuser",
});

//string welcome_big5="舧ㄓ眅竤獿肚叫块㈥┪⑿...\n欢迎来到「金庸群侠传」，请按回车继续...";
string welcome_big5=HIW"Welcome to JYQX II，Select GB(Enter) or BIG5(B)"NOR;

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
        set("channel_id", "连线精灵");
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
                write("现在时空已经封闭了，不能进入！！ \n");
                destruct(ob);
                return;
        }

        if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
                write("你的地址在本 MUD 不受欢迎。\n");
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
        printf(RED"您现在从"YEL"%s"RED"连线进入。%s\n目前共有"YEL"%s"RED"位巫师、"YEL"%s"RED"位玩家在线，还有"YEL"%s"RED"位用户在尝试连接。\n\n"NOR,
        str,ip_cnt-1?"在这个地址上，还有"+YEL+chinese_number(ip_cnt-1)+RED+"位其他玩家。":"",
        chinese_number(wiz_cnt), chinese_number(ppl_cnt), chinese_number(login_cnt) );
        p_num=0;  //counter of Player's login times.
        write(HIW"您的英文名字："NOR);
        input_to( (: get_id :), ob );
}

void get_id(string arg, object ob)
{
        object ppl;
        object *usr;
        int i, wiz_cnt;

        arg = lower_case(arg);
        if( !check_legal_id(arg)) {
                write(HIW"您的英文名字："NOR);
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
                        write("对不起，" + MUD_NAME + "的使用者已经太多了，请待会再来。\n");
                        destruct(ob);
                        return;
                }
        }
#endif

        if( query_wiz_level(SECURITY_D->get_status(arg)) < wiz_lock_level ) {
                write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
                        + " 以上的人才能连线。\n");
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
                        write(HIW"请输入密码："NOR);
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("您的人物储存挡出了一些问题，请利用 guest 人物通知巫师处理。\n");
                destruct(ob);
                return;
        }

        write("使用 " + (string)ob->query("id") + " 这个名字将会创造一个新的人物，您确定吗(y/n)？");
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
        write(HBRED "这是您第"+chinese_number(p_num)+"次密码输入错误。" NOR);
/*
        write(MAG"\n\n请重新输入您的英文名字："NOR);
        input_to("get_id", ob,1);
*/
        write(HIW"\n\n请重新输入您的密码：");
	input_to("get_passwd", 1, ob);
        return;
        }
        write(HIR"对不起，您已经三次输入密码错误，请想好了再来！\n");
                //write("密码错误！\n");
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
                write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
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
        write("请您重新创造这个人物。\n");
        confirm_id("y", ob);
}

void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("好吧，欢迎下次再来。\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "有人从别处( " + query_ip_number(ob)
                        + " )连线取代你所控制的人物。\n");
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
                write("使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
                input_to("confirm_id", ob);
                return;
        }

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write(MAG"好吧，那么请重新输入您的英文名字："NOR);
                input_to("get_id", ob);
                return;
        }
        write( @TEXT

请输入您的高姓大名，由于这个名字代表你的人物，而且以后不能更改，
务必慎重择名（不雅观的姓名将被删除）。另：请不要选择金庸小说中
已有人物姓名。

(除了名字之外，本 mud 有许多取绰号、别称的设计，所以郑重建议您
 取一个比较像名字的中文名字。)
TEXT
        );
        write(HIM"您的中文名字："NOR);
        input_to("get_name", ob);
}

void get_name(string arg, object ob)
{
        if( !check_legal_name(arg) ) {
                write("您的中文名字：");
                input_to("get_name", ob);
                return;
        }
        printf("%O\n", ob);
        ob->set("name", arg);
        write("请设定您的密码：");
        input_to("new_password", 1, ob);
}

void new_password(string pass, object ob)
{
        write("\n");
        if( strlen(pass)<5 ) {
                write("密码的长度至少要五个字符，请重设您的密码：");
                input_to("new_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write("请再输入一次您的密码，以确认您没记错：");
        input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
        mapping my;
        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("您两次输入的密码并不一样，请重新设定一次密码：");
                input_to("new_password", 1, ob);
                return;
        }

        write(@TEXT
一个人物的天赋对于他或她所修习的武艺息息相关。金庸群侠传中的人物大多具有
以下四项天赋：

        膂力：影响攻击能力及负荷量的大小。
        悟性：影响学习武功秘籍的速度及理解师傅的能力。
        根骨：影响体力恢复的速度及升级后所增加的体力。
        身法：影响防御及躲避的能力。

TEXT);
        my = ([]);
        write("您是否想自定天赋(y/n)？");
	input_to("get_choice",ob,my);
}

//added by long, 1999.7.6
void get_choice(string yn, object ob, mapping my)
{
        if (yn[0] != 'y' && yn[0] != 'Y') {
                write("\n现在由系统为您设定天赋。\n");
		random_gift(my);
		printf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]\n",
			my["str"], my["int"], my["con"], my["dex"]);
		write("您接受这一组天赋吗？(y/n)");
                input_to("get_gift", ob, my);
        }
        if (yn[0] == 'y' || yn[0] == 'Y') {
        printf("\n现在请您按以下顺序自定天赋。\n您的天赋总点数为80，请输入您的"+HIC"〖臂力〗"NOR+"点数(10-30)：");
        input_to("get_tf1", ob, my);
	}
}
void get_gift(string yn, object ob, mapping my)
{
        if (yn[0] != 'y' && yn[0] != 'Y') {
                random_gift(my);
                printf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]\n",
                      my["str"], my["int"], my["con"], my["dex"]);
		write("您同意这一组天赋吗(y/n)？");
                input_to("get_gift", ob, my);
        }
        if (yn[0] == 'y' || yn[0] == 'Y') {
                input_to("get_email", ob, my);
                write("\n您的电子邮件地址：");
        }
}

void get_tf1(string gift, object ob, mapping my)
{
	int tf1, rest;
        if(sscanf(gift,"%d",tf1)!=1 || tf1 > 30 || tf1 <10) {
                write("点数值必须在"+HIR"10-30"NOR+"之间！\n");
		printf("您的天赋总点数为80，请输入您的"+HIC"〖臂力〗"NOR+"点数(10-30)：");
                input_to("get_tf1",ob,my);
        }
	else {
	        my["str"]=tf1;
		rest=80-tf1;
		printf("\n您的天赋点数尚余%d点，请输入您的"+HIC"〖悟性〗"NOR+"点数(10-30)：", rest);
		input_to("get_tf2",ob,my);
		}
}

void get_tf2(string gift, object ob, mapping my)
{
	int tf2, rest, rest1, rest2;
        if(sscanf(gift,"%d",tf2)!=1 || tf2 > 30 || tf2 <10) {
                write("点数值必须在"+HIR"10-30"NOR+"之间！\n");
		printf("\n您的天赋点数尚余%d点，请输入您的"+HIC"〖悟性〗"NOR+"点数(10-30)：", 80-my["str"]);
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
	        printf("\n您的天赋点数尚余%d点，请输入您的"+HIC"〖根骨〗"NOR+"点数(%d-%d)：", rest, rest2, rest1);
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
		printf("点数值必须在"+HIR"%d-%d"NOR+"之间！\n", rest2, rest1);
	        printf("您的天赋点数尚余%d点，请输入您的"+HIC"〖根骨〗"NOR+"点数(%d-%d)：", rest, rest2, rest1);
                input_to("get_tf3",ob,my);
        }
	else {
	        my["con"]=tf3;
		my["dex"]=80-my["str"]-my["int"]-my["con"];
		if( my["dex"] < 10 || my["dex"] > 30 )
		{
			write("您得设定不对，请重新设定！\n");
			printf("您的天赋总点数为80，请输入您的"+HIC"〖臂力〗"NOR+"点数(10-30)：");
                	input_to("get_tf1",ob,my);
        	}
		else {
	                printf("\n膂力[%d]， 悟性[%d]， 根骨[%d]， 身法[%d]\n",
        	              my["str"], my["int"], my["con"], my["dex"]);
		write("您接受这一组天赋吗？(y/n)");
	        input_to("get_choice2", ob, my);
		}
	}
}
void get_choice2(string yn, object ob, mapping my)
{
        if (yn[0] != 'y' && yn[0] != 'Y') {
		write("请重新设定您的天赋。\n您的天赋总点数为80，请输入您的"+HIC"〖臂力〗"NOR+"点数(10-30)：");
               	input_to("get_tf1",ob,my);
        }
        if (yn[0] == 'y' || yn[0] == 'Y') {
                write("\n您的电子邮件地址：");
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
                write("电子邮件地址需要是 id@address 的格式。\n");
                write("您的电子邮件地址：");
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

        write("您要扮演男性(m)的角色或女性(f)的角色？");
        input_to("get_gender", ob, user);
}

void get_gender(string gender, object ob, object user)
{
        write("\n");
        if( gender=="" ) {
                write("您要扮演男性(m)的角色或女性(f)的角色？");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "男性");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "女性" );
        else {
                write("对不起，您只能选择男性(m)或女性(f)的角色：");
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
                write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
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
        user->set("title", "普通百姓");
        user->set("birthday", time() );
        user->set("potential", 500);
        user->set("channels", ({ "chat", "rumor" }) );
// Added by Hop, 97.07.09
        if(user->query("gender") == "女性")
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

        write("\n目前权限：" + wizhood(user) + "\n");

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
                write("你正受处罚中，无法连线进入。\n");
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
                        if (user->query("gender")=="女性")
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
                                if ( user->query("gender")=="女性")
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
                                if ( user->query("gender")=="女性")
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
                        case "剑":
                                weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
                                weapon->move(user);
                                break;
                        case "刀":
                                weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
                                weapon->move(user);
                                break;
                        case "棍":
                                weapon = new("/d/npc/m_weapon/weapon/m_club",1);
                                weapon->move(user);
                                break;
                        case "杖":
                                weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
                                weapon->move(user);
                                break;
                        case "鞭":
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
        if(sscanf(lot_list[i], "%s(%s) buy 第%d期彩票 %s at %s", name,id,turn,number,time) == 5 )
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
        if(sscanf(lot_list[i], "%s(%s) buy 第%d期彩票 %s at %s", name,id,turn,number,time) == 5 )
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

                printf("\n按 Enter 键继续......");
                input_to("",1);

                if( ob->query("new_mail") ) {
                        write( sprintf(HIG + "\n您有 %d 封新信！快看你的信箱吧！\n\n" + NOR,ob->query("new_mail")));
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
                tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
                        ({user}));
        }
        login_ob=new(LOGIN_OB);
        login_ob->set("id",user->query("id"));
        login_ob->restore();
        write("你上次连线是从" + HIR +login_ob->query("last_from") + NOR + " on " + HIR +ctime(login_ob->query("last_on"))+ NOR + "\n");
        destruct(login_ob);

//changed by long
        CHANNEL_D->do_channel( this_object(), "sys",
        sprintf("%s(%s)由%s连线进入，共清除"+reclaim_objects() + " 个变数。\n", user->name(), user->query("id"),
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
                tell_room(environment(user), user->query("name") + "重新连线回到
这个世界。\n",
                ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s)由%s重新连线进入。", user->query("name"), user->query("id"), query_ip_name(user)) );
        UPDATE_D->check_user(user);
        STATUS_D->check_user(user);
}

int check_legal_id(string id)
{
        int i;

        i = strlen(id);

        if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
                write(HIR"对不起，你的英文名字必须是 3 到 12 个英文字母。\n"NOR);
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write(HIR"对不起，你的英文名字只能用英文字母。\n"NOR);
                        return 0;
                }
        if( member_array(id, banned_id)!=-1 ) {
                write(HIR"对不起，这种英文名字会造成其他人的困扰。\n"NOR);
                return 0;
        }

        return 1;
}

int check_legal_name(string name)
{
        int i;

        i = strlen(name);

        if( (strlen(name) < 2) || (strlen(name) > 10 ) ) {
                write("对不起，你的中文名字必须是 1 到 5 个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("对不起，你的中文名字不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，请您用「中文」取名字。\n");
                        return 0;
                }
        }
        if( member_array(name, banned_name)!=-1 ) {
                write("对不起，这种名字会造成其他人的困扰。\n");
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
        printf(RED"自二零零零年十月四日已有"+YEL+chinese_number(number-1)+RED"个访问者，最高在线"YEL+chinese_number(max_online)+RED"人。\n"NOR);

}

void del_sleeped(object me)
{
        if (objectp(me) &&  me->query("sleeped"))
                me->set("sleeped",0);
}

