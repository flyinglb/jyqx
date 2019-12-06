
inherit ROOM;

void create()
{
	set("short", "�ײĵ�����");
	set("long",
	     "\nһ���ţ�һ�ɸ������㼸��Ҫ��Ϣ�ˡ��������ǹײ�(guancai)��\n"
	);
	set("exits", ([
		"west" : __DIR__"guancai1",
	]));
	set("item_desc", ([
		"guancai" : "\n�ײİ�ܽ�ʵ���������Щ�ҳ���\n" ,
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_move", "move");
        add_action("do_move", "open");
        add_action("do_knock", "knock");
}


int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg!="guancai") return notify_fail("��Ҫ�ƿ�ʲô��\n");
	message_vision(
		"\n$N�ƿ��ײİ壬ֻ����ৡ���һ��, �ص���ͻȻ�׹�һ����\n"+
		"һ������ٿ�����,���ۡ���һ��������$N��С��,�֡��ۡ���һ�����˳�����\n"+
                "һ�����˴Ӷ���̽��ͷ����������м�ؿ���$Nһ�ۣ������ְѵذ�����ˡ�\n", this_player());
        if((int)this_player()->query("qi")<250) this_player()->die();
        else this_player()->unconcious();
	return 1;
}

int do_knock(string arg)
{
        object me,hole;
	string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="guancai" ) {
		message_vision("\n$N���������ùײİ壬���ˣ������ƺ��ǿյġ�\n", this_player());
	}
	if( sscanf(arg, "guancai %s", dir)==1 ) 
	{
		if( dir=="3" || dir=="three") {
		if(!objectp(present("hole", environment(me))))
		{
		message_vision("\n$N�ڹײİ����������������£�ֻ��֨ѽһ����\n"+"������һ˫�ְѹײİ��ƿ��ˡ�\n", this_player());
                hole = new("/d/city2/obj/hole");
                hole->move("/d/city2/guancai2");
		}
	        }   
		else return notify_fail("\n��������˹ײİ弸�£����ʲôҲû������\n");
	}		
return 1;
}

int do_enter(string arg)
{
 if( !arg || arg!="guancai" ) return 0;
 return notify_fail(" �봩�ײİ尡���㲻�����Ŷݼס�\n");
 return 1;
}	

