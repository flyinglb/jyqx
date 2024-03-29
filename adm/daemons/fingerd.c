// fingerd.c
//modified by long

#include <net/dns.h>

int query_only_ip(object *ob);
void create() { seteuid( getuid() ); }

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
	return (month?month + "m":"") + (day?day + "d":"") + 
	(hour?hour + "h":"") + min + "m";
}

int sort(object ob1, object ob2)
{
	if (!interactive(ob1)) return -1;
	if (!interactive(ob2)) return 1;
//        return strcmp(query_ip_number(ob1), query_ip_number(ob2));
        return strcmp(""+(string)ob1->query("id"), ""+(string)ob2->query("id"));
}

string finger_all()
{
	object *ob;
	string msg;
	int i, ips;

	ob = filter_array(objects(), (: userp :));
	ob = sort_array(ob, (: sort :));
	msg = "";
	if ( !wizardp(this_player()) )  // player finger
	{
		for(i=0; i<sizeof(ob); i++) {
			if( !this_player()->visible(ob[i]) ) continue;
			msg = sprintf("%s%-14s%-14s%-14s\n",
				msg, ob[i]->query("name"), ob[i]->query("id"),
				!interactive(ob[i])?"断线中":query_idle(ob[i]) + "s");
		}
        	return "◎" + MUD_NAME + "\n" +
		"——————————————————\n"
		+ "姓名          帐号          发呆\n" +
		"——————————————————\n"
		+ msg +
		"——————————————————\n";
	} else  	// wizard finger
	{
		for (i=0;i<sizeof(ob);i++)
			if (this_player()->visible(ob[i])) break;
		msg += sprintf("%s%-13s%-14s%-14s%-7s%-=29s\n",
			environment(ob[i])?" ":"*",
			ob[i]->query("name"), ob[i]->query("id"),
			age_string( (int)ob[i]->query("mud_age")), 
			(!interactive(ob[i])?"断线中":query_idle(ob[i]) + "s"),
			query_ip_name(ob[i]));
		for(i=i+1; i<sizeof(ob); i++) {
			if( !this_player()->visible(ob[i]) ) continue;
			msg += sprintf("%s%-13s%-14s%-14s%-7s%-=29s\n",
				environment(ob[i])?" ":"*",
				ob[i]->query("name"), ob[i]->query("id"),
				age_string( (int)ob[i]->query("mud_age")), 
				(!interactive(ob[i])?"断线中":query_idle(ob[i]) + "s"),
				query_ip_number(ob[i]) && query_ip_number(ob[i]) == query_ip_number(ob[i-1])?
				"地址同上":query_ip_name(ob[i]));
		}
		ips=query_only_ip(ob);
	        return "◎ " + MUD_NAME + "\n" +
		"———————————————————————————————————————\n"
		" 姓名         帐号          年龄          发呆   连线\n" +
		"———————————————————————————————————————\n"
		+ msg +
		"———————————————————————————————————————\n"
		"* 表示登录中，排除由同一IP登录的人后，实际有："+ips+"人\n";
	}
}
	
string finger_user(string name)
{
	object ob, body;
	string msg;
	int public_flag;

/*	if( sscanf(name, "%s@%s", name, mud)==2 ) {
		GFINGER_Q->send_finger_q(mud, name, this_player(1));
		return "网路指令传送过程可能需要一些时间，请稍候。\n";
	}
*/
	ob = new(LOGIN_OB);
	ob->set("id", name);
    if( !ob->restore() ) {destruct(ob); return "没有这个玩家。\n";}
	
	
	if ( !wizardp(this_player()) )  // player finger
	{
	
		if( objectp(body = find_player(name)) && geteuid(body)==name )
		{
			public_flag = body->query("env/public")?1:0;
		} else 
		{
			body = LOGIN_D->make_body(ob);
            if( !body->restore() ) {destruct(body); return "没有这个玩家。\n";}
			public_flag = body->query("env/public")?1:0;
			destruct(body);
		}		
		
		msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
			"电子邮件地址：\t%s\n上次连线：\t%s\n\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			public_flag?ob->query("email"):"不告诉你",
			ctime(ob->query("last_on"))
		);
		if( objectp(body = find_player(name)) && geteuid(body)==name ) {
			if (this_player()->visible(body))
			msg += sprintf("\n%s目前正在连线中。\n", body->name(1));
		}
	} else  	// wizard finger
	{
		msg =  sprintf("\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
			"电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",
			ob->query("id"),
			ob->query("name"),
			SECURITY_D->get_status(name),
			ob->query("email"),
			ob->query("last_from"),
			ctime(ob->query("last_on"))
		);
		if( objectp(body = find_player(name)) && geteuid(body)==name ) {
			if (this_player()->visible(body))
			msg += sprintf("\n%s目前正在从 %s(%s) 连线中。\n", body->name(1), query_ip_name(body),
				query_ip_number(body));
		}
	}	
	
	destruct(ob);
	return msg;
}

varargs string remote_finger_user(string name, int chinese_flag)
{
	object ob, body;
	string msg;

	ob = new(LOGIN_OB);
	ob->set("id", name);
	if( !ob->restore() )
		return chinese_flag ? "没有这个玩家。\n" : "No such user.\n";
	if( chinese_flag ) msg =  sprintf(
		"\n英文代号：\t%s\n姓    名：\t%s\n权限等级：\t%s\n"
		"电子邮件地址：\t%s\n上次连线地址：\t%s( %s )\n\n",
		ob->query("id"),
		ob->query("name"),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	else msg =  sprintf(
		"\nName\t: %s\nStatus\t: %s\nEmail\t: %s\nLastOn\t: %s( %s )\n\n",
		capitalize(ob->query("id")),
		SECURITY_D->get_status(name),
		ob->query("email"),
		ob->query("last_from"),
		ctime(ob->query("last_on"))
	);
	if( body = find_player(name) ) {
		if( !this_player() || this_player()->visible(body) )
			msg += chinese_flag ?
				("\n" + ob->query("name") + "目前正在线上。\n"):
				("\n" + capitalize(name) + " is currently connected.\n");
	}

	destruct(ob);
	return msg;
}

object acquire_login_ob(string id)
{
	object ob;

	if( ob = find_player(id) ) {
		// Check if the player is linkdead
		if( ob->query_temp("link_ob") )
			return ob->query_temp("link_ob");
	}
	ob = new(LOGIN_OB);
	ob->set("id", id);
	return ob->restore() ? ob : 0;
}

string get_killer()
{
	int i;
	string msg;
	object *ob = users();

	msg = "";
	for (i = 0; i < sizeof(ob); i++)
		if ((int)ob[i]->query_condition("killer"))
			msg = sprintf("%s%-50s 赏金：%s\n",
				msg, ob[i]->short(1), MONEY_D->price_str(ob[i]->query("combat_exp") / 5000 * 10000));
	if (msg == "")
		return "本城治安良好。\n";
	else
		return "现在本城正在缉拿以下人犯：\n\n" + msg;
}

int query_only_ip(object *ob)
{	
	int i,j,k,count,total;

	total=sizeof(ob);
	for ( i=0; i<sizeof(ob); i++)
	{
		count=1;k=sizeof(ob);
		for (j=0; j<k;j++)
			if (j!=i&&query_ip_name(ob[i])==query_ip_name(ob[j]) )
			{
				ob=ob-({ob[j]});
				count++;
				k=sizeof(ob);
			}
		total=total-count+1;
	}
	return total;
}
