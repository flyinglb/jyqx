// Room: /city/leitai.c
// Date: Feb.27 1998 by Java
inherit ROOM;
string look_shelf();
int do_quit(string arg);

void create()
{
	set("short", "��̨");
	set("long", @LONG
����һ�����ɼ�������̨����׳��ʵ��ľ������һƬƽ̨���Ľǵ�֧����
�߹����ĸ�����������Ĺ��ڶ�������ؿ���̨�ϵ�������䡣��̨�����и�
������(shelf) �������ް�������ȫ��
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"shelf" : (: look_shelf :),
	]));

	set("exits", ([
		"up"        : __DIR__"wudao",
		"eastdown"  : __DIR__"wudao1",
		"westdown"  : __DIR__"wudao2",
		"southdown" : __DIR__"wudao3",
		"northdown" : __DIR__"wudao4",
	]));
	set("objects", ([
		__DIR__"npc/referee": 1,
	]));
	set("no_clean_up", 0);
	set("no_openshelf", 1);
        set("no_suck", 1);
        set("no_get_from", 1);
	setup();
}

string look_shelf()
{
	return 
"\n
һ��������ͷ�ı����ܣ����ᶼ����ò���ˡ�
���ϰ�����: 
                 �ֵ�(blade)    ����(sword)
                 ����(staff)    ����(whip)
                 ����(hammer)   ����(club)
                 ����(throwing) �̱�(dagger)
                 �ּ�(armor)

�μӱ����߿��԰���Ҫ�������ȡ(take)ʹ�á�

                                ��������̨  ����
\n";
}

void init()
{
//	add_action("do_yun","yun");
//	add_action("do_yun","exert");
//	add_action("do_quit","hit");
//	add_action("do_quit","fight");
//	add_action("do_quit","qiecuo");
        add_action("do_shexin","shexin");
	add_action("do_get","get");
	add_action("do_quit","quit");
	add_action("do_quit","exit");
	add_action("do_quit","dazuo");
	add_action("do_quit","exercise");
	add_action("do_quit","learn");
	add_action("do_quit","xue");
	add_action("do_quit","practice");
        add_action("do_quit","open");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
	add_action("do_take","take");
	add_action("do_open","open");
	add_action("do_close","close");
}
int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("����ϯֻ�б��������ܽ�ȥ��\n");
	me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}
int do_yun(string arg)
{
	if (arg=="roar")
	{
        write(this_player()->query("name")+"��ר�ı���ɣ�\n");
	return 0;
	}
	return 1;
}
int do_shexin(string arg)
{
        write(this_player()->query("name")+"����Ŀ����������\n");
        return 1;
}
int do_get(string arg)
{
        write(this_player()->query("name")+"���������������\n");
	return 1;
}
int do_quit(string arg)
{
        write(this_player()->query("name")+"��ר�ı���ɣ�\n");
	return 1;
}
int do_open(string arg)
{
if(wizardp(this_player()))
{
message_vision("$N�ѱ����������ˡ�\n", this_player());
        return 1;
}
 else return 0;
}
int do_close()
{
	if(wizardp(this_player()))
	{
		message_vision("$N�����������ѱ����ܸ����ˡ�\n", this_player());
		this_object()->set("no_openshelf", 1);
		return 1;
	}
	else return 0;
}
int do_take(string arg)
{
	object obj,ob;
	ob = this_player();
	if(this_object()->query("no_openshelf"))
	{
		message_vision("�Ǵ�����ʱ�򣬱����ܸ���ס�ˡ�\n", ob);
		return 1;
	}
	if( !arg || arg=="" )
	{
		message_vision("$Nվ�ڱ�����ǰ����û���Ҫʲô������\n", ob);
		return 1;
	}
	switch (arg)
	{
		case "sword":
			obj = new("/clone/weapon/changjian");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�ڳ�����\n",ob);
			break;
		case "blade":
			obj = new("/clone/weapon/gangdao");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�ڸֵ���\n",ob);
			break;
		case "staff":
			obj = new("/clone/weapon/gangzhang");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�˸��ȡ�\n",ob);
			break;
		case "whip":
			obj = new("/clone/weapon/changbian");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�����ޡ�\n",ob);
			break;
		case "club":
			obj = new("/clone/weapon/qimeigun");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ����ü����\n",ob);
			break;
		case "hammer":
			obj = new("/clone/weapon/hammer");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ��������\n",ob);
			break;
		case "throwing":
			obj = new("/clone/weapon/lianzi");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�������ӡ�\n",ob);
			break;
		case "dagger":
			obj = new("/clone/weapon/dagger");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ��ذ�ס�\n",ob);
			break;
		case "armor":
			obj = new("/clone/weapon/tiejia");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�����ס�\n",ob);
			break;
		default:
			message_vision("$Nվ�ڱ�����ǰ����û���Ҫʲô������\n", ob);
	}
	return 1;
}
