// mailbox.c

inherit ITEM;
inherit F_SAVE;

mapping *mails;

void get_mail_text(mapping mail, string str);

void create()
{
	set_name("信箱", ({ "mailbox", "box" }) );
	set("long",
		"这是一个用来寄信、收信的信箱，你可以用以下指令来处理你的邮件：\n\n"
		"mail <某人>               寄信给别人。\n"
		"forward <信件编号> <某人> 将某封信转寄给别人。\n"
		"from                      查看信箱中的信件。\n"
                "yuedu <信件编号>          阅读一封信件。\n"
                "diuqi <信件编号>          丢弃一封信件。\n"
	);
	set("unit", "个");
	set("no_drop", 1);
	set("no_get", 1);
	set("no_insert", 1);

	seteuid(getuid());
}

int set_owner(string id)
{
	set("owner_id", id);
	return restore();
}

void init()
{
	if( this_player() && environment()==this_player() ) {
		set_owner( (string)this_player()->query("id") );
		this_player()->set_temp("mbox_ob", this_object());
		set_name( this_player()->name(1) + "的信箱", ({ "mailbox", "box" }) );
		add_action("do_mail", "mail");
		add_action("do_forward", "forward");
		add_action("do_from", "from");
		add_action("do_read", "yuedu");
		add_action("do_discard", "diuqi");
	}
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
        if( file_size(query_save_file()+__SAVE_EXTENSION__) > 2048*1024 ) {
                write("对不起信箱已满，无法收信。\n");
                return ;
        }
	if( !pointerp(mails) ) mails = ({ mail });
	else mails += ({ mail });
	save();
}

void send_mail(string rcvr, mapping mail)
{
	object ppl, ob, mbx;
	mapping mydb;

	// Get the mailbox or make a new one if not found.
	ppl = find_player(rcvr);
	if(ppl) 
	{
		mbx = ppl->query_temp("mbox_ob");
			tell_object(ppl, HIY
			+ "\n您有信呦！请查看一下您身上的信箱!\n\n" + NOR);
	} 
	else {
		ob = FINGER_D->acquire_login_ob(rcvr);
        	if(!ob) 
        	{
                	write("没有这个人存在。\n");
                	return;
        	}

        // ob->set("new_mail", 1);

        mydb = ob->query_entire_dbase();
        if( mydb["new_mail"] = 0)
          mydb["new_mail"] = 1;
        else
        mydb["new_mail"] += 1;
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
                  ob->save();
	}
	mbx->receive_mail(mail);

/*
	object ppl, ob, mbx;

	// Acquire the login object of receiver and mark the arrival of newmail.
	ob = FINGER_D->acquire_login_ob(rcvr);
	if( !ob ) {
		write("没有这个人存在。\n");
		return;
	}
	ob->add("new_mail", 1);
	ob->save();

	// Get the mailbox or make a new one if not found.
	ppl = find_player(rcvr);
	if(ppl)
	{
        tell_object(ppl, HIY "有你的信哟！\n" NOR );
		mbx = ppl->query_temp("mbox_ob");
	}
	else {
		ob = FINGER_D->acquire_login_ob(rcvr);
        	if(!ob) 
        	{
                	write("没有这个人存在。\n");
                	return;
        	}
	if( !mbx ) {
		mbx = new(MAILBOX_OB);
		mbx->set_owner(rcvr);
	}

	// Receive the mail and destruct the objects if receiver is off-line.
	mbx->receive_mail(mail);
	if(!ppl) {
		destruct(mbx);
		destruct(ob);
	}

*/

}

int do_mail(string arg)
{
	mapping mail;

	if( this_player()!=environment() ) return 0;

	if( !arg || arg=="" )
		return notify_fail("你要寄信给谁？\n");
        if( file_size(DATA_DIR+"mail/"+arg[0..0]+"/"+arg+__SAVE_EXTENSION__) > 2048*1024 )
                return notify_fail("对不起"+arg+"的信箱已经满了，无法收到你的信\n");

	mail = ([
		"from":	this_player()->name(1) + "(" + this_player()->query("id") + ")",
		"title": "无题",
		"to": arg,
		"time": time(),
		"text": ""
	]);
	write("信件标题：");
	input_to("get_mail_title", mail);
	return 1;
}

void get_mail_title(string str, mapping mail)
{
	if( str!="" ) mail["title"] = str;
	write("信件内容：\n");
	this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
	mail["text"] = str;
	write("您自己要留一份备份吗(y/n)？[n]");
	input_to("confirm_copy", mail);
}

void confirm_copy(string yn, mapping mail)
{
	if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);
	send_mail(mail["to"], mail);
	write("Ok.\n");
}

int do_from()
{
	int i;

	if( !pointerp(mails) || !sizeof(mails) ) {
		write("你的信箱中目前没有任何信件。\n");
		return 1;
	}
	write("你的信箱中现在共有 " + sizeof(mails) + " 封信件：\n\n");
	for(i=0; i<sizeof(mails); i++)
		printf("%2d %-50s 寄信人：%-20s\n",
			i+1, mails[i]["title"], mails[i]["from"] );
	write("\n");
	return 1;
}

int do_read(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要读哪一封信？\n");

	if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	printf("信件标题：%s\n寄 信 人：%s\n\n%s\n",
		mails[num]["title"], mails[num]["from"], mails[num]["text"] );

	return 1;
}

int do_discard(string arg)
{
	int num;

	if( !arg || !sscanf(arg, "%d", num) )
		return notify_fail("你要丢弃哪一封信？\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	if(num == 0)
		mails = mails[num+1..sizeof(mails)-1];
	else
		mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
	save();
	write("Ok.\n");

	return 1;
}

int do_forward(string arg)
{
	string dest;
	int num;
	mapping m;

	if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
		return notify_fail("你要将哪一封信转寄给别人？\n");

	if( !pointerp(mails) || num > sizeof(mails) )
		return notify_fail("没有这个编号的信件。\n");

	num --;

	m = ([]);
	m["title"] = mails[num]["title"];
	m["text"] = mails[num]["text"];
	m["time"] = mails[num]["time"];
	m["from"] = mails[num]["from"] + "/转寄自" + this_player()->query("name");
	m["to"] = dest;
	send_mail( dest, m );
	write("Ok.\n");

	return 1;
}

void owner_is_killed() { destruct(this_object()); }
